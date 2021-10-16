#include <stdio.h>

struct student
{
    int marks1,marks2,marks3,avg;
    char name[25];
}
stud[100],t;
 
void main()
{
    int i,j,n;
    printf("Enter the no of students\n");
    scanf("%d",&n);
    printf("enter student:name markofsubject1 markofsubject2 markofsubject3\n");
    
    for(i=0;i<n;i++)
   { 
        scanf("%s %d %d %d",stud[i].name,&stud[i].marks1,&stud[i].marks2,&stud[i].marks3);
   

       
   }
       for(i=0;i<n;i++)
       {
               
    stud[i].avg=(stud[i].marks1+stud[i].marks2+stud[i].marks3)/3;
       }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(stud[j].avg<stud[j+1].avg)
            {
                t=stud[j];
                stud[j]=stud[j+1];
                stud[j+1]=t;
            }
        }
    }
    
    printf("\nStudent info in terms of marks from highest to lowest\n");
    printf("RANK\t\t\tNAME\t\t\tSCORE\n");
    printf("---------------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t\t%s\t\t\t%d\t\t\t\n",i+1,stud[i].name,stud[i].avg);
    }
}