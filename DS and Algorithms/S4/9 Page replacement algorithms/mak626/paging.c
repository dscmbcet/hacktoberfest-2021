#include <limits.h>
#include <stdio.h>

int front = -1, rear = -1, q[100];

void enQueue(int x, int limit) {
    if (rear == -1)
        rear = front = 0;
    else
        rear = (rear + 1) % limit;

    q[rear] = x;
}

int deQueue(int limit) {
    int temp = q[front];
    if (rear == front)
        rear = front = -1;
    else
        front = (front + 1) % limit;
    return temp;
}

int queueContains(int x, int limit) {
    if (rear == -1) //IMPORTANT: QUE EMPTY
        return 0;

    if (q[rear] == x)
        return 1;
    for (int i = front; i != rear; i = (i + 1) % limit) {
        if (q[i] == x)
            return 1;
    }
    return 0;
}

int isQueueFull(int limit) {
    return (rear + 1) % limit == front;
}

void initQueue(int limit) {
    //Initialize queue
    front = rear = -1;
    for (int i = 0; i < limit; i++) {
        q[i] = -1;
    }
}

void printQue(int limit, int page, int hit) {
    if (rear == -1)
        return;

    if (hit)
        printf("%d %c: ", page, 'H');
    else
        printf("%d %c: ", page, 'M');

    for (int j = front;; j = (j + 1) % limit) {
        printf("%d ", q[j]);
        if (j == rear) {
            printf("\n");
            break;
        }
    }
}

void fcfsPageReplacement(int frames, int page_count, int pages[]) {
    int page_fault = 0;
    printf("\nFCFS Page Replacement\n");
    initQueue(frames);

    for (int i = 0; i < page_count; i++) {
        if (queueContains(pages[i], frames)) {
            printQue(frames, pages[i], 1);
            continue;
        } else {
            page_fault++;
            if (isQueueFull(frames)) {
                deQueue(frames);
                enQueue(pages[i], frames);
            } else {
                enQueue(pages[i], frames);
            }
        }
        printQue(frames, pages[i], 0);
    }
    printf("Page faults:%d\n", page_fault);
}

void optimalPageReplacement(int frames, int page_count, int pages[]) {
    int page_fault = 0;
    printf("\nOptimal Page Replacement\n");

    initQueue(frames);

    for (int i = 0; i < page_count; i++) {
        if (queueContains(pages[i], frames)) {
            printQue(frames, pages[i], 1);
            continue;
        } else {
            page_fault++;
            if (isQueueFull(frames)) {
                int farthestPagePosition = INT_MIN;
                int queReplacePosition = INT_MIN;

                //Find which index to replace
                for (int j = front;; j = (j + 1) % frames) {
                    int pagePresent = 0;

                    //Find first index of each page of queue in pages[] from i
                    for (int k = i + 1; k < page_count; k++) {
                        if (pages[k] == q[j]) {
                            if (k > farthestPagePosition) {
                                farthestPagePosition = k;
                                queReplacePosition = j;
                            }

                            pagePresent = 1;
                            break;
                        }
                    }
                    if (!pagePresent) //This j is the farthest because its not present in pages[] from i
                    {
                        queReplacePosition = j;
                        break;
                    }

                    if (j == rear) //loop termination
                        break;
                }

                q[queReplacePosition] = pages[i];
            } else {
                enQueue(pages[i], frames);
            }
        }

        printQue(frames, pages[i], 0);
    }
    printf("Page faults:%d\n", page_fault);
}

void leastRecentlyUsedReplacement(int frames, int page_count, int pages[]) {
    int page_fault = 0;
    printf("\nLeast Recently Used Replacement\n");
    initQueue(frames);

    for (int i = 0; i < page_count; i++) {
        if (queueContains(pages[i], frames)) {
            printQue(frames, pages[i], 1);
            continue;
        } else {
            page_fault++;
            if (isQueueFull(frames)) {
                int farthestPagePosition = INT_MAX; //Change
                int queReplacePosition = INT_MAX;   //Change

                //Find which index to replace
                for (int j = front;; j = (j + 1) % frames) {
                    int pagePresent = 0;

                    //Find first index of each page of queue in pages[] from i-1 to 0
                    for (int k = i - 1; k > 0; k--) //CHANGE
                    {
                        if (pages[k] == q[j]) {
                            if (k < farthestPagePosition) //Change
                            {
                                farthestPagePosition = k;
                                queReplacePosition = j;
                            }
                            pagePresent = 1;
                            break;
                        }
                    }

                    if (!pagePresent) //This j is the farthest because its not present in pages[] from i-1
                    {
                        queReplacePosition = j;
                        break;
                    }

                    if (j == rear) //loop termination
                        break;
                }

                q[queReplacePosition] = pages[i];
            } else {
                enQueue(pages[i], frames);
            }
        }
        printQue(frames, pages[i], 0);
    }
    printf("Page faults:%d\n", page_fault);
}

void main() {
    int frames, page_count;
    printf("Enter frames and page_count:");
    scanf("%d %d", &frames, &page_count);
    int pages[100];
    printf("Enter pages:");
    for (int i = 0; i < page_count; i++) {
        scanf("%d", &pages[i]);
    }
    fcfsPageReplacement(frames, page_count, pages);
    optimalPageReplacement(frames, page_count, pages);
    leastRecentlyUsedReplacement(frames, page_count, pages);
}

/*
https://www.youtube.com/watch?v=8rcUs5RutX0
FCFS 
3 15
7 0 1 2 0 3 0 4 2 3 0 3 1 2 0

https://www.youtube.com/watch?v=q2BpMvPhhrY
OPTIMAL
4 20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

https://www.youtube.com/watch?v=dYIoWkCvd6A
Least Recently Used (LRU)
4 13
7 0 1 2 0 3 0 4 2 3 0 3 2 

3 20
7 2 3 1 2 5 3 4 6 7 7 1 0 5 4 6 2 3 0 1
*/