//7. Write a function to print given number of terms of Fibonacci series.

#include<stdio.h>

void printfibonacci  ( int n) 
{
if (n < = 0)
{
printf("Number of terms must be positive.\n");
return;
}

if (n == 1)
{
printf("0\n");
return;
}

int a= 0, b=1;

printf("%d",a);
printf("%d",b);

for (int i= 2; i< n; i++)
{
int nextTerm = a+b;
printf("%d", nextterm);
a=b;
b=nextTerm;
}
int main()
{
int num;

printf("Enter the number of terms you want in fibonassi series");
scanf("%d", &num);
printfibonacci(num);

return 0;
}



