#include<stdio.h>

void primenum(int n)
{
	int count=1, flag, i=2, j;
	while(count <= n)
	 {
		  flag = 0;
		  for(j=2; j <= i/2; j++)
		  {
			   if(i%j==0)
			   {
			    flag=1;
			    break;
			   }
		  }
		  if(flag==0)
		  {
			   printf("%d\t",i);
			   count++;
		  }
		  i++;
	 }
}

void main()
{
	 int n;
	 printf("How many prime numbers? \n");
	 scanf("%d", &n);
	primenum(n);
	 
}
