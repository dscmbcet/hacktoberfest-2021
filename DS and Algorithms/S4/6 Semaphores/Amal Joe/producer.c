#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>

#define MAX 5

// to identify the errors occurred during runtime
extern int errno;

struct data
{
    int buffer[MAX];
    int index;
    sem_t mutex, full, empty;
} * d;

int main()
{
    bool new = true;
    // create shared memory if it doesnt exist
    // shm_open will return -1 if shared memory exists since we are using O_CREAT and O_EXCL flags together
    int fd = shm_open("/shared", O_CREAT | O_RDWR | O_EXCL, 0777);
    if (fd == -1 && errno == EEXIST)
    {
        // shared memory exists
        new = false;
        fd = shm_open("/shared", O_CREAT | O_RDWR, 0777);
    }
    // limit the size of shared memory
    ftruncate(fd, sizeof(struct data));
    // map the shared memory object
    d = mmap(NULL, sizeof(struct data), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (new)
    {
        // if shared memory is just created, initialise the values
        d->index = 0;
        sem_init(&(d->mutex), 10, 1);
        sem_init(&(d->full), 10, 0);
        sem_init(&(d->empty), 10, MAX);
    }
    while (true)
    {
        int x;
        sem_getvalue(&(d->full), &x);
        if (x == MAX)
        {
            printf("Buffer full\n");
            //exit(0);
        }
        // Produce
        int y = rand() % 100;
        // Add element to the buffer
        sem_wait(&(d->empty));
        sem_wait(&(d->mutex));
        d->buffer[d->index] = y;
        d->index++;
        sem_post(&(d->mutex));
        sem_post(&(d->full));
        // Print a message and sleep for 1s
        printf("Putting %d\n", y);
        sleep(1);
    }
}