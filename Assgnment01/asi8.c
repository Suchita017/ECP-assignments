#include<stdio.h>

int main()
{
int num1, num2, num3;
float average;

printf("Enter the first integer:");
scanf("%d", &num1);

printf("Enter the second integer:");
scanf("%d", &num2);

printf("Enter the third integer:");
scanf("%d", &num3);

average = (num1 + num2 + num3)/3.0;

printf("the average of %d, %d, and %d is %2.f\n",num1, num2, num3, average);

return 0;
}
