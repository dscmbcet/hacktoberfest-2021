#include <stdio.h>
int main()
{
  int array[100]; int se; int i; int n;

  printf("Enter number of elements in array\n");
  scanf("%d", &n);

  printf("Enter %d elements\n", n);

  for (i= 0; i < n; i++)
    scanf("%d", &array[i]);

  printf("Enter a number to search\n");
  scanf("%d", &se);

  for (i = 0; i < n; i++)
  {
    if (array[i] == se)
    {
      printf("Given element is present at: %d\n", i+1);
      break;
    }
  }
  if (i == n)
    printf("Given element is not present in the array\n");

  return 0;
}