#include<stdio.h>
#include<math.h>
void fcfs(int disk[],int hs,int eval,int n)
{
    int sum=abs(hs-disk[0]);
    for(int i=1;i<n;i++)
    {
        sum=sum+abs(disk[i-1]-disk[i]);
    }
    printf("The total head movement is of %d cylinders\n",sum);
    printf("The seek sequence is\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",disk[i]);
    }
}

void scan(int disk[],int hs,int eval,int n)
{
    int sum=hs;
    int htemp=disk[0];
    int order[n+1],y=0,y1,temp;
    for(int i=1;i<n;i++)
    {
        if(htemp<disk[i])
        {
            htemp=disk[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(disk[i]<hs)
        {
            order[y++]=disk[i];
            y1=y;
        }
    }
    for(int i=0;i<y1;i++)
    {
        for(int j=i;j<y1;j++)
        {
            if(order[i]<order[j])
            {
                temp=order[i];
                order[i]=order[j];
                order[j]=temp;
            }
        }
    }
    order[y1]=0;
    y1=y1+1;
    for(int i=0;i<n;i++)
    {
        if(disk[i]>hs)
        {
            order[y1++]=disk[i];
        }
    }
    for(int i=y+1;i<n+1;i++)
    {
        for(int j=i;j<n+1;j++)
        {
            if(order[i]>order[j])
            {
                temp=order[i];
                order[i]=order[j];
                order[j]=temp;
            }
        }
    }
    sum=sum+htemp;
    printf("The total head movement is of %d cylinders\n",sum);
    printf("The seek sequence is\n");
    for(int i=0;i<n+1;i++)
    {
        printf("%d\t",order[i]);
    }
}

void cscan(int disk[],int hs,int eval,int n)
{
    int sum;
    int ltemp=disk[0];
    int order[n+2],y=0,y1,temp;
    for(int i=1;i<n;i++)
    {
        if(ltemp>disk[i])
        {
            ltemp=disk[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(disk[i]<hs&&disk[i]>=ltemp)
        {
            ltemp=disk[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(disk[i]>hs)
        {
            order[y++]=disk[i];
            y1=y;
        }
    }
    for(int i=0;i<y1;i++)
    {
        for(int j=i;j<y1;j++)
        {
            if(order[i]>order[j])
            {
                temp=order[i];
                order[i]=order[j];
                order[j]=temp;
            }
        }
    }
    order[y1++]=eval;
    order[y1]=0;
    y1=y1+1;
    for(int i=0;i<n;i++)
    {
        if(disk[i]<hs)
        {
            order[y1++]=disk[i];
        }
    }
    for(int i=y+1;i<n+2;i++)
    {
        for(int j=i;j<n+2;j++)
        {
            if(order[i]>order[j])
            {
                temp=order[i];
                order[i]=order[j];
                order[j]=temp;
            }
        }
    }
    sum=(eval-hs)+ltemp;
    printf("\nThe total head movement is of %d cylinders\n",sum);
    printf("The seek sequence is\n");
    for(int i=0;i<n+2;i++)
    {
        printf("%d\t",order[i]);
    }
}

void main()
{
    int z;
    do
    {
    int x=0;
    int n,hs,eval,m,err;
    printf("Enter the number of requests\n");
    scanf("%d",&n);
    printf("Enter the end value\n");
    scanf("%d",&eval);
    do
    {
        printf("Enter the head start\n");
        scanf("%d",&hs);
        if(hs<eval)
        {
            m=0;
        }
        else
        {
            m=1;
            printf("Head start should be small than end value\n");
        }
    }while(m==1);
    int disk[n];
    do
    {
    printf("Enter the process request\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&disk[i]);
        while(disk[i]>=eval)
        {
            printf("The resource request should be less than end value\n");
            scanf("%d",&err);
            disk[i]=err;
        }
    }
    printf("The enter disk queue is \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",disk[i]);

    }
        printf("\nTo confirm press 1.\nTo re-enter press 0\n");
        scanf("%d",&x);
    }while(x==0);
    int y=0;
    do
    {
        int ch;
        printf("To do FCFS algorithm press 1\nTo do SCAN algorithm press 2\nTo do C-SCAN algorithm press 3\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            fcfs(disk,hs,eval,n);
            break;

        case 2:
            scan(disk,hs,eval,n);
            break;

        case 3:
            cscan(disk,hs,eval,n);
            break;

        default:
            printf("\nInvalid option\n");
            break;
        }
        printf("\nTo continue with the same resources press 1, else press any other number\n");
        scanf("%d",&y);
    }while(y==1);
    printf("\nTo continue the program press 1,else press any other number\n");
    scanf("%d",&z);
    }while(z==1);
}