#include<stdio.h>
void main()
{
    int n,i,j,temp,a[20];
    printf("\nEnter the no: of numbers:");
    scanf("%d",&n);
    printf("\nEnter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    for (i = 0; i < n;i++)
    {
        printf("%d\t", a[i]);
    }
}