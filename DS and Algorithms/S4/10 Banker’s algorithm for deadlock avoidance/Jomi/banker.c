#include <stdio.h>
#include <stdlib.h>
void safety(int curr_alloc[20][20], int avail[20], int need[20][20]);
void resource_request();
void display();
void input();
int choice, n, i, j, resource, max[20][20], curr_alloc[20][20], avail[20], need[20][20];

void main()
{
    input();
    do
    {
        printf("\n1.Safety Algorithm\n2.Resource_Request\n3.Exit\nEnter your choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            safety(curr_alloc, avail, need);
        }

        else if (choice == 2)
        {
            resource_request();
        }
    } while (choice != 3);
}

void input()
{
    printf("Enter the no: of processes:");
    scanf("%d", &n);
    printf("Enter the no: of resource type:");
    scanf("%d", &resource);
    printf("Enter the max need of each process:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < resource; j++)
            scanf("%d", &max[i][j]);
    }

    printf("Enter the current allocation of each process:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < resource; j++)
        {
            scanf("%d", &curr_alloc[i][j]);
            need[i][j] = max[i][j] - curr_alloc[i][j];
        }
    }
    printf("Enter the current availability:");
    for (i = 0; i < resource; i++)
        scanf("%d", &avail[i]);
}

void safety(int curr_alloc[20][20], int avail[20], int need[20][20])
{
    int i, j, work[20], finish[20], safe_sequence[20], index = 0, flag = 0;
    for (i = 0; i < resource; i++)
    {
        work[i] = avail[i];
    }

    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    while (index < n)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {

                for (j = 0; j < resource; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }

                if (j == resource)
                {
                    for (int k = 0; k < resource; k++)
                        work[k] = work[k] + curr_alloc[i][k];
                    finish[i] = 1;
                    safe_sequence[index++] = i;
                    flag = 1;
                }
            }
        }

        if (flag == 0)
        {
            display();
            printf("\nSystem not in safe state\n");
            return;
        }
    }

    display();

    if (flag == 1)
    {
        printf("\nSystem is in safe state.\n");
        printf("Safe Sequence:");
        for (i = 0; i < n; i++)
            printf("\tP%d", safe_sequence[i]);
        printf("\n");
    }
}

void resource_request()
{
    int request[resource], process_id, temp_avail[20], temp_need[20][20], temp_alloc[20][20];
    printf("Enter the process id requesting resource:");
    scanf("%d", &process_id);
    printf("Enter the request:");
    for (i = 0; i < resource; i++)
    {
        scanf("%d", &request[i]);
    }

    for (j = 0; j < resource; j++)
    {
        if (request[j] > need[process_id][j])
        {
            printf("\nCurrent request is greater than maximum claim.\nThe request cannot be granted.\n");
            return;
        }
    }

    for (j = 0; j < resource; j++)
    {
        if (request[j] > avail[j])
        {
            printf("\nCurrent request is greater than maximum available.\nThe request cannot be granted.\n");
            return;
        }
    }

    for (i = 0; i < resource; i++)
    {
        temp_avail[i] = avail[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < resource; j++)
        {
            temp_alloc[i][j] = curr_alloc[i][j];
            temp_need[i][j] = need[i][j];
        }
    }

    for (i = 0; i < resource; i++)
    {
        temp_avail[i] = temp_avail[i] - request[i];
        temp_alloc[process_id][i] += request[i];
        temp_need[process_id][i] -= request[i];
    }

    safety(temp_alloc, temp_avail, temp_need);
}

void display()
{
    printf("AVAILABLE:\t");
    for (j = 0; j < resource; j++)
        printf("%d ", avail[j]);
    printf("\nPROCESS\t\t\tMAXIMUM\t\t\t\tALLOCATION\t\t\tNEED\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d ", i);
        printf("\t\t\t");
        for (j = 0; j < resource; j++)
            printf("%d ", max[i][j]);
        printf("\t\t\t");
        for (j = 0; j < resource; j++)
            printf("%d ", curr_alloc[i][j]);
        printf("\t\t\t");
        for (j = 0; j < resource; j++)
            printf("%d ", need[i][j]);

        printf("\n");
    }
}