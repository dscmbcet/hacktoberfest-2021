#include <stdio.h>
#include <ctype.h>
#include <string.h>
FILE *fp1,*fp2, *fp3;
int digitCount = 0;
int lineCount = 0;
void displayNumbers(int numbers[]);
int readInputAndWriteToFile()
{
    char ch;
    fp1 = fopen("input.log", "w");
    printf("Enter the C program\nNote: Append EOF using CTRL+d\n");
    while ((ch = getchar()) != EOF)
    {
        fputc(ch, fp1);
    }
    fclose(fp1);
}
int parseUserInputsFromFile(int numbers[])
{
    char ch;
    fp1 = fopen("input.log", "r");
    fp2 = fopen("identifiers.log", "w");
    fp3 = fopen("specialCharacters.log", "w");
    while ((ch = fgetc(fp1)) != EOF)
    {
        if (isdigit(ch))
        {
            int num = ch - '0';
            ch = fgetc(fp1);
            while (isdigit(ch))
            {
                num = num * 10 + ch - '0';
                ch = fgetc(fp1);
            }
            numbers[digitCount++] = num;
            ungetc(ch, fp1);
        }
        else if (isalpha(ch))
        {
            putc(ch, fp2);
            ch = fgetc(fp1);
            while (isalpha(ch) || isdigit(ch) || ch == '_' || ch == '$')
            {
                fputc(ch, fp2);
                ch = fgetc(fp1);
            }
            fputc(' ', fp2);
            ungetc(ch, fp1);
        }
        else if (ch == '\n')
        {
            ++lineCount;
        }
        else if (ch == ' ' || ch == '\t')
        {
        }
        else
        {
            fputc(ch, fp3);
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}
int checkIfIdentifierOrKeyword(char str[])
{
    if (strcmp("if", str) == 0 ||
        strcmp("do", str) == 0 ||
        strcmp("if", str) == 0 ||
        strcmp("for", str) == 0 ||
        strcmp("int", str) == 0 ||
        strcmp("char", str) == 0 ||
        strcmp("case", str) == 0 ||
        strcmp("else", str) == 0 ||
        strcmp("float", str) == 0 ||
        strcmp("while", str) == 0 ||
        strcmp("static", str) == 0 ||
        strcmp("double", str) == 0 ||
        strcmp("switch", str) == 0 ||
        strcmp("printf", str) == 0)
    {
        return 1;
    }
    return 0;
}
void parseIdentifiers()
{
    char ch;
    char str[10];
    fp2 = fopen("identifiers.log", "r");
    printf("\nThe identifiers and keywords are: \n\n");
    int k = 0;
    while ((ch = fgetc(fp2)) != EOF)
    {
        if (ch != ' ')
        {
            str[k++] = ch;
        }
        else
        {
            str[k] = '\0';
            if (checkIfIdentifierOrKeyword(str))
            {
                printf("`%s` is a keyword\n", str);
            }
            else
            {
                printf("`%s` is an identifier\n", str);
            }
            k = 0;
        }
    }
    fclose(fp2);
}
void parseSpecialSymbols()
{
    char ch;
    printf("\nSpecial characters are\n");
    fp3 = fopen("specialCharacters.log", "r");
    while ((ch = fgetc(fp3)) != EOF)
    {
        printf("%c ", ch);
    }
    printf("\n");
    fclose(fp3);
}

void displayNumbers(int numbers[])
{
    int i;
    if (digitCount)
    {
        printf("\nThe numbers in the program are: ");
        for (i = 0; i < digitCount; ++i)
        {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    }
}
int main()
{
    int numbers[100];
    readInputAndWriteToFile();
    parseUserInputsFromFile(numbers);
    parseIdentifiers();
    parseSpecialSymbols();
    displayNumbers(numbers);
    printf("\nTotal number of lines is %d\n", lineCount);
    return 0;
}