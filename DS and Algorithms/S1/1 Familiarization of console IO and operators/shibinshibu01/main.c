#include<stdio.h>
#include<math.h>
#define pi 3.14
void main()
{   
    float a,b,sum,rad,area,s1,s2,s3,s,areatri;
    //Display “Hello World”
    printf("Hello World");

    //Read two numbers, add them and display their sum
    printf("\nEnter two numbers to add: ");
    scanf("%f %f",&a,&b);
    sum = a+b;
    printf("The sum of %.3f and %.3f is %.2f",a,b,sum);

    //Read the radius of a circle, calculate its area and display it
    printf("\nEnter the radius of the circle: ");
    scanf("%f",&rad);
    area=pi*(rad*rad);
    printf("The area of the circle with radius %.2f is %.2f",rad,area);

    //Area of the triangle after reading its sides
    printf("\nInput the 3 sides:");
	scanf("%f %f %f",&s1,&s2,&s3);
	if(s1+s2>s3&&s2+s3>s1&&s3+s1>s2){
		s=4*s1*s1*s2*s2-pow(s1*s1+s2*s2-s3*s3,2);
		areatri=sqrt(s)/4;
		printf("Area of the triangle= %.2f",areatri);
	}
	else 
		printf("Such a trianle does not exists");

}