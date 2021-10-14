#include <stdio.h>
int main() {
   int n, am = 0, r, temp;
   printf("Enter an integer: ");
   scanf("%d", &n);
   temp = n;
 
   while (temp != 0) {
       r = temp % 10;
       am = am  + r*r*r;
       temp /= 10;
   }
 
   if (am == n)
       printf("%d is an armstrong number.",temp);
   else
       printf("%d is not an armstrong number.", temp);
 
   return 0;
}
