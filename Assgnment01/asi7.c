#include<stdio.h>

int main()
{
int num;

printf("Enter a 4-digit number:");
scanf("%d", &num);

if (num < 1000 || num > 9999)
{
printf("Error: please enter a 4-digit number.\n");

return 1;
}

int thousands = num / 1000;
int hundreds = (num / 100) % 10;
int tens = (num / 10) % 10;
int ones = num % 10;

printf("a. face value of each decimal digit:\n");
printf("%d\t", thousands);
printf("%d\t", hundreds);
printf("%d\t", tens);
printf("%d\t",ones);

printf("b. place value of each decimal digit:\n");
printf("%d = %d000 + %d00 + %d0 + %d\n", num, thousands, hundreds, tens, ones);

int reversed= ones * 1000 + tens * 100 + hundreds * 10 + thousands;

printf("c. number in revers order: %d\n", reversed);

return 0;

}
