#include<stdio.h>

int main()
{

char inputchar;
int asciivalue;

printf("Enter a character:");
scanf("%c", &inputchar);

asciivalue = inputchar;

printf("ASCII value of '%d':\n",asciivalue);
printf("Decimal: %d\n",asciivalue);
printf("hexadecimal: %x\n", asciivalue);
printf("octal: %o\n", asciivalue);


return 0;
}
