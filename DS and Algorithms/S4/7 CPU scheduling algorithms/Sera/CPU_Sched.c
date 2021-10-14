#include <stdio.h>
#include <stdlib.h>

struct process
{
    int id;
    int burst_time;
    int arrival_time;
    int priority;
    int start_time;
    int end_time;

    int waiting_time;
    int turn_around_time;

    // For round robin scheduling
    int remaining_burst_time;
    int previous_end_time;
    int done;
} P[30];
int n;
int ready_queue[20], front = -1, rear = -1;
int time_slice;
void input(int priority, int slice)
{

    printf("\nEnter no. of processes:");
    scanf("%d", &n);
    if (slice)
    {
        printf("Enter time slice:");
        scanf("%d", &time_slice);
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nProcess P%d", i + 1);
        P[i].id = i + 1; //P1,P2....
        P[i].done = 0;   //not done

        printf("\nEnter burst time:");
        scanf("%d", &P[i].burst_time);
        printf("Enter arrival time:");
        scanf("%d", &P[i].arrival_time);
        if (priority)
        {
            printf("Enter priority:");
            scanf("%d", &P[i].priority);
        }

        P[i].remaining_burst_time = P[i].burst_time;
        P[i].previous_end_time = P[i].arrival_time;
        P[i].waiting_time = 0; // currently 0
    }
}
int calculations(int i, int start)
{
    P[i].start_time = start;  // start for the process p1
    start += P[i].burst_time; // start for the new process p2
    P[i].end_time = start;    // end time for the process p1
    //waiting and TAT
    P[i].waiting_time = P[i].start_time - P[i].arrival_time;
    P[i].turn_around_time = P[i].end_time - P[i].arrival_time;
    P[i].done = 1;
    return start;
}
void display()
{
    int i;
    printf("\nP.ID\t\t\t\tBT\t\t\t\tAT\t\t\t\tEND\t\t\t\tWT\t\t\t\tTAT");
    for (i = 0; i < n; i++)
    {

        printf("\nP%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d", P[i].id, P[i].burst_time, P[i].arrival_time, P[i].end_time, P[i].waiting_time, P[i].turn_around_time);
    }
    float avgWT = 0, avgTAT = 0;
    for (i = 0; i < n; ++i)
    {
        avgWT += P[i].waiting_time;
        avgTAT += P[i].turn_around_time;
    }
    avgWT = avgWT / n;
    avgTAT = avgTAT / n;
    printf("\n\n\nAverage Waiting Time is %f and Average Turnaround Time is %f\n", avgWT, avgTAT);
}

//sort
void sortByAT()
{
    struct process temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (P[j].arrival_time > P[j + 1].arrival_time)
            {
                temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }
}
int sortByBT(int i, int j) // i=present process, j=start time
{
    int min = i;//i=p2 j11
    for (int j1 = i + 1; j1 < n; j1++)//j1=p3
    {
        if (j < P[j1].arrival_time)
        {
            break;
        }

        
        if (!P[j1].done && P[j1].burst_time < P[min].burst_time)//3<5
            {
                min = j1;//p5
            }
        
    }
    return min;//p2
}
int sortBypriority(int i, int j)
{
    int min = i;
    for (int j1 = i + 1; j1 < n; j1++)
    {
        if (j < P[j1].arrival_time)
        {
            break;
        }

        {
            if (!P[j1].done && P[j1].priority < P[min].priority)
            {
                min = j1;
            }
        }
    }
    return min;
}

// FCFS
void fcfs()
{
    input(0, 0);
    sortByAT();
    float avgWT = 0, avgTAT = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        //IF THE PROCESS HAS NOT ARRIVED EG: 1<2
        if (start < P[i].arrival_time)
            start = P[i].arrival_time;

       start = calculations(i,start);
    }
    display();
}

//sjfs
void sjfs()
{
    input(0, 0);
    sortByAT();

    int start = 0;
    int min = -1, k, calc;
    // struct process temp, min, next;

    for (int i = 0; i < n; i++)
    {
        if (!P[i].done)
        {
            if (start < P[i].arrival_time)
            {
                start = P[i].arrival_time;
            }
            min = sortByBT(i, start);//p1

            while (P[min].id != P[i].id)//min=p2 i=p2
            {
                start = calculations(min, start);//11,p5 done
                min = sortByBT(i, start);// p2
            }
            start = calculations(i, start);//start=6
            //  printf("\nP%d", P[i].id);
        }
    }
    display();
}

//priority_sch
void priority_sch()
{
    input(1, 0); //priority
    sortByAT();

    int start = 0;
    int min = -1, k, calc;
    // struct process temp, min, next;

    for (int i = 0; i < n; i++)
    {
        if (!P[i].done)
        {
            if (start < P[i].arrival_time)
            {
                start = P[i].arrival_time;
            }
            min = sortBypriority(i, start);

            while (P[min].id != P[i].id)
            {
                start = calculations(min, start);
                min = sortBypriority(i, start);
            }
            start = calculations(i, start);
        }
    }
    display();
}

//round_robin
void enq(int index)
{
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % n;
    ready_queue[rear] = index;
}
int deq()
{
    int item = ready_queue[front];

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % n;

    return item;
}
int queueContains(int index)
{
    if (ready_queue[rear] == index)
        return 1;
    for (int i = front; i != rear; i = (i + 1) % n)
    {
        if (ready_queue[i] == index)
            return 1;
    }
    return 0;
}
void round_robin()
{
    int index = 0, i;
    int start = 0;
    input(0, 1);

    enq(0);
    while (front != -1)
    {
        int current = deq();//P1

        if (start < P[current].arrival_time)
        {
            start = P[current].arrival_time;
        }

        P[current].waiting_time += start - P[current].previous_end_time;//P3=4 p1= 0+ (6-2)=4

        if (P[current].remaining_burst_time <= time_slice)
        {
            start += P[current].remaining_burst_time;//4
            P[current].end_time = start;
            P[current].turn_around_time = P[current].end_time - P[current].arrival_time;
            P[current].done = 1;
        }
        else
        {
            start += time_slice;//4
            P[current].previous_end_time = start;//8
            P[current].remaining_burst_time -= time_slice;//6  5
        }
        for (i = current + 1; i < n; i++)//p3
        {
            if (start < P[i].arrival_time )
                break;
            if (!P[i].done && !queueContains(i))
                enq(i);//P2 
        }
        if (!P[current].done)
            enq(current);//  P2 P1
    }

    display();
}

// Main
void main()
{

    int choice1 = 1;
    int choice ;

    while (choice1 == 1)
    {

        printf("\nCPU SCHEDULING");
        printf("\n1.First Come First Serve Scheduling");
        printf("\n2.Shortest Job First Scheduling");
        printf("\n3.Priority Scheduling");
        printf("\n4.Round Robin Scheduling");
        printf("\n5.Exit");
        printf("\nEnter Choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            fcfs();
            break;
        case 2:
            sjfs();
            break;
        case 3:
            priority_sch();
            break;
        case 4:
            round_robin();
            break;
        case 5:
            exit(0);
        default:
            printf("INVALID CODE\n");
        }
        printf("\nDo you want to continue?");
        scanf("%d",&choice1);
    }
}