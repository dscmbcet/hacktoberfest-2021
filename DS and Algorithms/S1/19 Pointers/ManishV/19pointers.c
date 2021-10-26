#include <stdio.h>

int sum(int *ptr, int n); //Function to calculate sum

int main()
{
    int n, i = 0;
    printf("Enter the no. of elements : ");
    scanf("%d", &n);
    int arr[n];
    int *ptr = arr; //declaring and defining pointer
    while (i < n)
    {
        printf("Enter the %d element : ", i + 1);
        scanf("%d", &arr[i]);
        i++;
    }
    printf("The sum is %d\n", sum(ptr, n));
    return 0;
}

int sum(int *ptr, int n)
{
    int sum = 0;
    int i = 0;
    while (i < n)
    {
        sum += *(ptr + i);
        i++;
    }

    return sum;
}