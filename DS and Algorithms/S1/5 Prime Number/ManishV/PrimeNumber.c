#include <stdio.h>

void PrintPrime(int n)
{
    int i;
    for (i = 2; i<= n; i=i+2)
    {

        if ((i == 2 || i == 3) || (i == 5 || i == 7))
        {
            printf("%d  ", i);
            if (i == 2)
            {
                i = 1;
            }
        }
        else if ((i % 3 == 0 || i % 5 == 0) || i % 7 == 0)
        {
            continue;
        }
        else
        {
            printf("%d  ", i);
        }
    }
}

    int main()
    {
        int n;
        printf("Enter the last number : ");
        scanf("%d", &n);
        PrintPrime(n);

        return 0;
    }