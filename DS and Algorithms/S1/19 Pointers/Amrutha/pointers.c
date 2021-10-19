#include<stdio.h>
void main()
{
    int n,i,sum=0;

    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    int *ptr=arr;

    //getting inputs
    printf("\nEnter %d Elements:",n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    //display entered values
    printf("You entered: \n");
    for (i=0;i<n;i++)
    {
        printf("%d\t\t",*(ptr+i));
    }

    //sum of elements
    for (i=0;i<n;i++)
    {
        sum+=*ptr;
        *ptr++;
    }
    printf("\nSum = %d",sum);

}