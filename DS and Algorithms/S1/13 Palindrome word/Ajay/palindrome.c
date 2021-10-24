#include<stdio.h>
#include<string.h>
void main()
{
    char str[100],rstr[100];
    int j=0;
    printf("Enter the string\n");
    scanf("%s",str);
    for(int i=strlen(str)-1;i>=0;i--)
    {
        rstr[j]=str[i];
        j++;
    }
    if(strcmp(str,rstr)==0)
    {
        printf("%s is palindrome",str);
    }
    else
    {
        printf("%s is not palindrome",str);
    }
}
