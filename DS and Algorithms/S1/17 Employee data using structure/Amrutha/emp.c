#include <stdio.h>
 
//structure declaration
struct employee{
    char name[30];
    int empId;
    int  salary;
};
 
int main()
{
    int i=0, n=0;
    printf("Enter number of employees:");
    scanf("%d",&n);
    
    //declare structure variable
    struct employee emp[n];
     
    for(i=0;i<n;i++)
    {
    //getting employee details
       printf("\nEnter details of employee %d:\n",i+1);
       printf("Name :");          
       scanf("%s",emp[i].name);
       printf("\nID no. :");            
       scanf("%d",&emp[i].empId);
       printf("\nSalary :");        
       scanf("%d",&emp[i].salary);
     
    //printing employee details
       printf("\nEntered detail of employee %d: ",i+1);
       printf("\nName : %s",emp[i].name);
       printf("\nId no. : %d",emp[i].empId);
       printf("\nSalary : %d\n",emp[i].salary);
    }
    return 0;
}