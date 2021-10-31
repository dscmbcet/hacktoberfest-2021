#include<stdio.h>
void main()
{
float num,large=0,seclarge=0,i=0;
int n;
printf("Enter the number of numbers:");
scanf("%d",&n);
printf("Enter %d numbers:",n);
    while(i<n)
    {
        scanf("%f",&num);
    if(i==0)
    {
        large=num;
    }
    else if(num>large)
    {
        seclarge=large;
        large=num;
    }
    else if(num>seclarge)
    {
        seclarge=num;
    }
    i++;
    }
printf("\nSecond largest number is %.2f",seclarge);
}