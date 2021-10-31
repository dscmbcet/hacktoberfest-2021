/*Create a file and perform the following

Write data to the file
Read the data in a given file & display the file content on console
append new data and display on console*/
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1000
void readFile(FILE * fp1);
int main()
{
    //Write data to the file
    FILE *fp1;
    char data [50];
    char dataToAppend[BUFFER_SIZE];
    printf("Opening file");
    fp1 = fopen("File1.txt","w");
    if (fp1 == NULL)
    {
        printf("Could not open file File1.txt" );
    }
    printf("\nEnter inpt to write in File.txt : ");
        while (strlen (gets ( data ) ) > 0)
        {
            fputs(data, fp1);
            fputs("\n", fp1);
        }
    printf("closing file\n");
    fclose(fp1);

    //Read the data in a given file & display the file content on console
    if ((fp1 = fopen ("File1.txt", "r")) == NULL)
    {
        printf ("Error! opening file");
    }
        printf ("The File content: ");
        readFile(fp1);
        fclose(fp1);
    
    //Append new data and display on console
    fp1 = fopen("File1.txt","a");
    if (fp1 == NULL)
    {
        printf("Could not open file File1.txt" );
    }
    printf("\nEnter data to append: ");
    while (strlen (gets ( data ) ) > 0)
        {
            fgets(dataToAppend, BUFFER_SIZE, stdin);
            fputs(dataToAppend, fp1);
        }
    fflush(stdin);

    fp1 = freopen("File.txt", "r", fp1);
    printf("\nSuccessfully appended data to file. \n");
    printf("Changed file contents:\n");
    readFile(fp1);
    fclose(fp1);
    return 0;
}
void readFile(FILE * fp1)
{
    char ch;

    do 
    {
        ch = fgetc(fp1);

        putchar(ch);

    } while (ch != EOF);
}

    