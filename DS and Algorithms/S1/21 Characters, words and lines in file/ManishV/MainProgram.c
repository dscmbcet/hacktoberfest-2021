#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * iptr = NULL; //creating file pointer for input.txt
    char ch;
    int chars=0, words=0, lines=0;

    iptr = fopen("input.txt", "r");



    if (iptr == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(0);
    }
 
    while ((ch = fgetc(iptr)) != EOF)
    {
        chars++;


        if (ch == '\n' || ch == '\0')
            lines++;


        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }

   if (chars > 0)
    {
        words++;
        lines++;
    }
fclose(iptr);
FILE * optr = fopen("output.txt","w"); // creating file pointer for output.txt

   if (optr == NULL)
    {
        printf("\nUnable to open file.\n");
        exit(0);
    }
    fprintf(optr,"Total characters = %d\n", chars);
    fprintf(optr,"Total words      = %d\n", words);
    fprintf(optr,"Total lines      = %d\n", lines);

fclose(optr);
    

    return 0;
}