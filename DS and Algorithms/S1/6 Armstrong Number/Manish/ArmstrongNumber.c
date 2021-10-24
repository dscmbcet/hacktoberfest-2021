#include <stdio.h>
#include <string.h>
int main()
{
    int n, i=0, t;
    printf("Enter the number : ");
    scanf("%d", &n);
    int temp=n;
    while(n>0)
    {
    t= n%10;
    i += (t*t*t);
    n= n/10;
    }
    if(i==temp)
    printf("Number is an Armstrong number\n");
    else
    printf("Number is not an Armstrong number\n");

    return 0;
}