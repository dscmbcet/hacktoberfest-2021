#include <stdio.h>

int largest_of_three_numbers(int i, int j, int k){
    int out = k;

    if (i > j){
        if (i > k){
            out = i;
        }else{
            out = k;
        }
    }else if (j > k){
        out = j;
    }

    return out;
}

int main(){

    int a;
    int b;
    int c;

    printf(" Enter the number1 = ");
    scanf("%d", &a);

    printf("\n Enter the number2 = ");
    scanf("%d", &b);
    
    printf("\n Enter the number3 = ");
    scanf("%d", &c);

    int result = largest_of_three_numbers(a, b, c);

    printf("result is %d", result);

    return 0;
}