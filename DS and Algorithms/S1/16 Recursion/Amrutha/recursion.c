#include <stdio.h>
 
int sum (int num)
{
    if (num != 0)
    {
        return (num % 10 + sum (num / 10));
    }
    else
    {
       return 0;
    }
}
 
int main()
{
    int num, result;
 //inputs
    printf("Enter the number: ");
    scanf("%d", &num);
    result = sum(num);
    printf("Sum of digits of %d is %d\n", num, result);
    return 0;
}
