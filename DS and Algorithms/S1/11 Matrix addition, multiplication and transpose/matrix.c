#include<stdio.h>
#include<stdlib.h>

// function to add two 3x3 matrix
void add(int m[3][3], int n[3][3], int sum[3][3])
{
	int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            sum[i][j] = m[i][j] + n[i][j];
}


void multiply(int m[3][3], int n[3][3], int result[3][3])
{
	int i,j,k;
  for(i=0; i < 3; i++)
  {
    for(j=0; j < 3; j++)
    {
      result[i][j] = 0; 
      for (k = 0; k < 3; k++)
      result[i][j] += m[i][k] * n[k][j];
    }
  }
}

// function to find transpose of a 3x3 matrix
void transpose(int matrix[3][3], int trans[3][3])
{
	int i,j;
  for ( i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      trans[i][j] = matrix[j][i];
}

// function to display 3x3 matrix
void display(int matrix[3][3])
{
	int i,j;
  for(i=0; i<3; i++)
  {
    for(j=0; j<3; j++)
      printf("%d\t",matrix[i][j]);

    printf("\n"); // new line
  }
}

void getmatrix(int t[][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("Enter element [%d][%d] : ",i,j);
            scanf("%d",&t[i][j]);
        }
    }
}
// main function
int main()
{
  // matrix
  int a[3][3],b[3][3],c[3][3];
  
  getmatrix(a);
  getmatrix(b);

  // print both matrix 
  printf("First Matrix:\n");
  display(a);
  printf("Second Matrix:\n");
  display(b);

  // variable to take choice
  int choice;

  // menu-driven
  do
  {
    // menu to choose the operation
    printf("\nChoose the matrix operation,\n");
    printf("----------------------------\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("3. Transpose\n");
    printf("4. Exit\n");
    printf("----------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add(a, b, c);
        printf("Sum of matrix: \n");
        display(c);
        break;
      case 2:
        multiply(a, b, c);
        printf("Multiplication of matrix: \n");
        display(c);
        break;
      case 3:
        printf("Transpose of the first matrix: \n");
        transpose(a, c);
        display(c);
        printf("Transpose of the second matrix: \n");
        transpose(b, c);
        display(c);
        break;
      case 4:
        printf("Thank You.\n");
        exit(0);
      default:
        printf("Invalid input.\n");
        printf("Please enter the correct input.\n");
    }
  }while(1);

  return 0;
}
