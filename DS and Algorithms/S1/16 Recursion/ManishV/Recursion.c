#include <stdio.h>

int SumOfDigits(int n)
{
    int sum = 0, temp;
    temp = n % 10;
    if (n <= 0)
        sum = temp;
    else
        sum = temp + SumOfDigits(n / 10);

    return sum;
}
int main()
{
int n;
printf("Enter the number : ");
scanf("%d", &n);
printf("The sum of the digits is : %d\n", SumOfDigits(n));
    return 0;
}