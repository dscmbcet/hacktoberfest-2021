#include <stdio.h>
void main()
{
    int n, i, j, t, A[30];
    printf("Enter the value of number n\n");
    scanf("%d", &n);
    printf("Enter the numbers into the array\n");
    for (j = 0; j < n; j++)
    {
        scanf("%d", &A[j]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                t = A[j];
                A[j] = A[j + 1];
                A[j + 1] = t;
            }
        }
    }
    printf("ARRAY IN ASCENDING ORDER\n");
    for (j = 0; j < n; j++)
    {
        printf("%d\t", A[j]);
    }

}