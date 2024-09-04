#include<stdio.h>

int main()
{
int num;

printf("Enter a number:");
scanf ("%d",&num);

printf("desimal: %d\n",num);
printf("octal: %o\n",num);
printf("hexadecimal: %x\n,num");

if(num >=0 && num <=255)

printf("character:%c\n",num);
else

printf("character: out of ASCII range\n"); 


return 0;

}
