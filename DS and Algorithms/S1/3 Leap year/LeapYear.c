#include<stdio.h>
#include<conio.h>

int main(){
    int year;
    printf("Enter a year :- ");
    scanf("%d",&year);
    if(year%100 == 0){
        if(year%400 == 0)
            printf("Leap Year");
        else
            printf("Not a leap year");
    }
    else{
        if(year%4 == 0)
            printf("Leap Year");
        else
            printf("Not a leap year");
    }
    getch();
}
