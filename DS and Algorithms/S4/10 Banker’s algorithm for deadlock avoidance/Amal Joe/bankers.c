#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESS 10
#define MAX_REQUEST 5

int available[MAX_REQUEST];
int max[MAX_PROCESS][MAX_REQUEST];
int alloc[MAX_PROCESS][MAX_REQUEST];
int need[MAX_PROCESS][MAX_REQUEST];
// n - no of process, m - no of resources
int n, m;

bool safety();
bool resource_req(int, int[]);
void display();
bool isLessThan(int[], int[]);

int main()
{
    printf("Enter the no of processes:\n");
    scanf("%d", &n);
    printf("Enter the no of resources:\n");
    scanf("%d", &m);
    printf("Enter available resources (a1 a2 a3...):\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter current allocation for resource p%d (c1 c2 c3...):\n", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
        printf("Enter maximum allocation for resource p%d (m1 m2 m3...):\n", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            if (need[i][j] < 0)
            {
                printf("Invalid inputs");
                return 1;
            }
        }
    }
    display();
    bool success = safety();
    if (!success)
    {
        return 1;
    }
    while (true)
    {
        char choice;
        printf("Do you want to request a resource? (y/n)\n");
        scanf(" %c", &choice);
        if (choice != 'y')
        {
            break;
        }
        int process;
        int request[MAX_REQUEST];
        printf("Enter process number:\n");
        scanf("%d", &process);
        printf("Enter resources required (r1, r2, r3...):\n");
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &request[i]);
        }
        resource_req(process, request);
    }
    return 0;
}

bool safety()
{
    int work[MAX_REQUEST];
    int finish[MAX_PROCESS];

    // sequence array will store the generated safe sequence
    int sequence[MAX_REQUEST];
    int seq_index = -1;

    // initialise finish to false
    for (int i = 0; i < n; i++)
    {
        finish[i] = false;
    }
    // initialise work to available
    for (int i = 0; i < m; i++)
    {
        work[i] = available[i];
    }
    // loop through all process untill it stops execution
    while (true)
    {
        // if atleast one process executes in one complete cycle, set flag to true
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (isLessThan(need[i], work) && finish[i] == false)
            {
                flag = true;
                // work = work + allocated[i] because after the process completes, it will release its allocated resources
                for (int j = 0; j < m; j++)
                {
                    work[j] += alloc[i][j];
                }
                finish[i] = true;
                sequence[++seq_index] = i;
            }
        }
        // if no process executed in the current cycle, break out of the loop
        if (!flag)
        {
            break;
        }
    }
    // if all processes completes its execution, length of safe sequence will be equal to no of process
    if (seq_index + 1 == n)
    {
        printf("Safe sequence exists:\n");
        for (int i = 0; i < n; i++)
        {
            printf("p%d ", sequence[i]);
        }
        printf("\n\n");
        return true;
    }
    else
    {
        printf("Safe sequence does not exist\n");
        return false;
    }
}

// check if a1 array has all elements less than or equal to corresponding elements of a2 array
bool isLessThan(int a1[], int a2[])
{
    for (int i = 0; i < m; i++)
    {
        if (a1[i] > a2[i])
        {
            return false;
        }
    }
    return true;
}

bool resource_req(int p, int request[])
{
    if (!isLessThan(request, need[p]))
    {
        printf("Request cannot be granted immediately since request is exceeding the maximum allocatable resource for the process p%d.\n\n", p);
        return false;
    }
    if (!isLessThan(request, available))
    {
        printf("Request cannot be granted immediately since request is exceeding the current available resources.\n\n", p);
        return false;
    }
    // assume the request is granted
    for (int i = 0; i < m; i++)
    {
        available[i] -= request[i];
        alloc[p][i] += request[i];
        need[p][i] -= request[i];
    }
    display();
    // check if the new state has a safety sequence
    bool success = safety();
    if (success)
    {
        printf("Request can be granted immediately since safe sequence can be generated.\n\n", p);
        return true;
    }
    // restore old state if request cannot be granted
    for (int i = 0; i < m; i++)
    {
        available[i] += request[i];
        alloc[p][i] -= request[i];
        need[p][i] += request[i];
    }
    printf("Request cannot be granted immediately since safe sequence cannot be generated.\n\n", p);
    return false;
}

void display()
{
    printf("\nProcess\tAllocated\tMax\tNeed\n");
    for (int i = 0; i < n; i++)
    {
        printf("p%d\t", i);
        for (int j = 0; j < m; j++)
        {
            printf("%d ", alloc[i][j]);
        }
        printf("\t\t");
        for (int j = 0; j < m; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("\t");
        for (int j = 0; j < m; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    printf("\nAvailable\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", available[i]);
    }
    printf("\n\n");
}

/*
5
3
3 3 2
0 1 0
7 5 3
2 0 0
3 2 2
3 0 2
9 0 2
2 1 1
2 2 2
0 0 2
4 3 3
y
1
1 0 2
y
4
3 3 0
n

*/