#include<stdio.h>
int main(){
int i, a, b, n, num;
puts("\n");
printf("Enter the number of numbers to be entered \n");
scanf("%d",&n);
printf("Enter the numbers \n");
for(i=0;i<n;i++)
{
     scanf("%d",&num);
     if(i==0)
     {
          a = num;
          b = num;
     }
     else if(num == -1)
     {
         break;
     }
     else if(num>a)
     {
          b = a; 
          a = num; 
     }
     else if(num>b)
     {
          b=num;
     }
 }

printf("the second largest number is: %d\n",b);
return 0;
}