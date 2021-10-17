#include <stdio.h>
void main()
{
    char str[150];
    int i, vowels, consonants, digits, spaces;
    vowels =  consonants =  spaces = 0;
    printf("Enter a  string: ");
    scanf("%[^\n]", str);
    for(i=0; str[i]!='\0'; ++i)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' ||
           str[i]=='o' || str[i]=='u' || str[i]=='A' ||
           str[i]=='E' || str[i]=='I' || str[i]=='O' ||
           str[i]=='U')
        {
            ++vowels;
        }
        else if((str[i]>='a'&& str[i]<='z') || (str[i]>='A'&& str[i]<='Z'))
        {
            ++consonants;
        }
        else if (str[i]==' ')
        {
            ++spaces;
        }
    }
    printf("No of Vowels: %d",vowels);
    printf("\nNo of Consonants: %d",consonants);
    printf("\nNo of White spaces: %d\n", spaces);
}
