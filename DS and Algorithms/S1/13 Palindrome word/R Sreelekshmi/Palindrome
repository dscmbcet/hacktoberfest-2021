#include <stdio.h>
#include <string.h>

int
main (void)
{
  char str[50], ch;
  int c = 0; int len;

  printf ("Enter string: ");
  gets (str);
  len = strlen (str);
  
  for (int i = 0; i < len; i++)
  {
      if(str[i]==str[len-i-1])
      {
          c++;
      }
      else
      {
          c=0;
      }
  }
  if(c>=1)
  {
    printf("Palindrome");
  }
  else
  {
    printf("Not palindrome");
  }
  return 0;
}