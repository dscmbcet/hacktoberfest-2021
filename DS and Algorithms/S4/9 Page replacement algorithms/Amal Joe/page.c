#include <stdio.h>

#define MAX 50
#define FRAMES_MAX 10

int n;
int frames_size;
int ref[MAX];
int frames[FRAMES_MAX];

int hits = 0;
int faults = 0;
int fcfs_index = 0;
int ch;

void allocate(int, int);
void page_replacement();
int find_fifo(int);
int find_optimal(int);
int find_lru(int);

int main()
{
    ch = 3;
    frames_size = 4;
    printf("Enter the size of reference string:\n");
    scanf("%d", &n);
    printf("Enter the reference string(r1 r2 r3...)):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ref[i]);
    }
    page_replacement();
    printf("Page hits: %d\n", hits);
    printf("Page faults: %d\n", faults);
    return 0;
}

void page_replacement()
{
    for (int i = 0; i < frames_size; i++)
    {
        frames[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int index;
        switch (ch)
        {
        case 1:
            index = find_fifo(ref[i]);
            break;
        case 2:
            index = find_optimal(i);
            break;
        default:
            index = find_lru(i);
            break;
        }
        allocate(index, ref[i]);
    }
}

void allocate(int index, int page)
{
    if (frames[index] == page)
    {
        hits++;
        printf("%d: Page Hit,\tFrames: ", page);
        for (int i = 0; i < frames_size; i++)
        {
            printf("%d ", frames[i]);
        }
        printf("\n");
        return;
    }
    // replace page if not found
    frames[index] = page;
    faults++;
    printf("%d: Page Fault,\tFrames: ", page);
    for (int i = 0; i < frames_size; i++)
    {
        printf("%d ", frames[i]);
    }
    printf("\n");
}

int find_fifo(int page)
{
    // check if page exists
    for (int i = 0; i < frames_size; i++)
    {
        if (frames[i] == page)
            return i;
    }
    // replace if not found
    int index = fcfs_index;
    fcfs_index = ++fcfs_index % frames_size;
    return index;
}

int find_optimal(int index)
{
    int page = ref[index];
    // check if page exists
    for (int i = 0; i < frames_size; i++)
    {
        if (frames[i] == page)
            return i;
    }
    // check if empty page exists
    for (int i = 0; i < frames_size; i++)
    {
        if (frames[i] == -1)
            return i;
    }
    // replace if not found
    int nearest[FRAMES_MAX];
    for (int i = 0; i < frames_size; i++)
    {
        nearest[i] = MAX + 1;
        for (int j = index + 1; j < n; j++)
        {
            if (ref[j] == frames[i])
            {
                nearest[i] = j;
                break;
            }
        }
    }
    int farthest = 0;
    for (int i = 0; i < frames_size; i++)
    {
        if (nearest[i] > nearest[farthest])
        {
            farthest = i;
        }
    }
    return farthest;
}

int find_lru(int index)
{
    int page = ref[index];
    // check if page exists
    for (int i = 0; i < frames_size; i++)
    {
        if (frames[i] == page)
            return i;
    }
    // check if empty page exists
    for (int i = 0; i < frames_size; i++)
    {
        if (frames[i] == -1)
            return i;
    }
    // replace if not found
    int nearest[FRAMES_MAX];
    for (int i = 0; i < frames_size; i++)
    {
        nearest[i] = -1;
        for (int j = index - 1; j >= 0; j--)
        {
            if (ref[j] == frames[i])
            {
                nearest[i] = j;
                break;
            }
        }
    }
    int farthest = 0;
    for (int i = 0; i < frames_size; i++)
    {
        if (nearest[i] < nearest[farthest])
        {
            farthest = i;
        }
    }
    return farthest;
}

/*
15
7 0 1 2 0 3 0 4 2 3 0 3 1 2 0

20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

*/