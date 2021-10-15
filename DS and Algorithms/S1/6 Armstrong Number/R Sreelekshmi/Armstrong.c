#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    int s=0; int ld;
    int c=n;
    
    while(c>0)
    {
        ld=c%10;
        s=s+(ld*ld*ld);
        c=c/10;
    }
    
    if(s==n)
    {
        printf("\nArmstrong number");
    }
    
    else
    {
        printf("\nNot Armstrong number");
    }
}    