#include <stdio.h>

float sum(float *ptr, int n); //Function to calculate sum
float avg(float sum, int n);  // Function to calculate the Average

int main()
{
    int n, i = 0;
    printf("Enter the no. of elements : ");
    scanf("%d", &n);
    float arr[n];
    while (i < n)
    {
        printf("Enter the %d element : ", i + 1);
        scanf("%f", &arr[i]);
        i++;
    }
    float Sum = sum(arr, n); //Calling sum function
    float Avg = avg(Sum, n); // Calling Average function
    printf("The sum is %.2f\n", Sum);
    printf("THe average is %.2f\n", Avg);
    return 0;
}

float sum(float *ptr, int n)
{
    float sum = 0;
    int i = 0;
    while (i < n)
    {
        sum += *(ptr + i);
        i++;
    }

    return sum;
}
float avg(float sum, int n)
{
    return (sum / n);
}
