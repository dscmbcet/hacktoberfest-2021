#include <stdio.h>
struct Employee
    {
      char name[30];
      int employeeid;
      float salary;
    };
    
int main(void)
  {
    struct Employee e[30];
    int n;
    printf("Enter the number of Employees\n ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {    
            printf("Enter the name of the employee\n");
            scanf("%s",e[i].name);
            printf("enter the employee id\n");
            scanf("%d",&e[i].employeeid);
            printf("enter the salary\n");
            scanf("%f",&e[i].salary);
        }
    printf("\n\n");
    for(int i=0;i<n;i++)
        {
          printf("Name:%s\nid:%d\nSalary:%f\n \n",e[i].name,e[i].employeeid,e[i].salary);
        }
  }