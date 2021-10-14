#include <stdio.h>
int main()
{
   int yr;
   printf("input yr:");
   scanf("%d", &yr);
      if(yr%400==0)
        printf("leap year");
      else if(yr%100==0)
        printf(" not leap year"); 
      else if(yr%4==0)
        printf("leap year"); 
      else
        printf("not a leap yr");
    return 0;
   
}
