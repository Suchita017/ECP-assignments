#include<stdio.h>

int main()
{
int num1,num2;

printf("Enter num1:");
scanf("%d",&num1);

printf("Enter num2:");
scanf("%d",&num2);

int sum = num1+num2;
int difference = num1-num2;
int product = num1 * num2;

printf("sum: %d\n",sum);
printf("difference: %d\n",difference);
printf("product: %d\n",product);

return 0;
}
