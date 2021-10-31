#include <stdio.h>
#include <math.h>

int main() {
   int num, copy, r, n = 0;
   float result = 0.0;

   printf("Enter an integer: ");
   scanf("%d", &num);

   copy = num;

   for (copy = num; copy != 0; ++n) {
       copy /= 10;
   }

   for( copy = num; copy != 0; copy /= 10) {
       r= copy % 10;

      result += pow(r, n);
   }

   if ((int)result == num)
    printf("%d is an Armstrong number.", num);
   else
    printf("%d is not an Armstrong number.", num);
   return 0;
}