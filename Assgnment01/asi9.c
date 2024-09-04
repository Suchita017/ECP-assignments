#include<stdio.h>
 int main()
 {
 int choice;

 float temperature, convertedTemperature;

 printf("Temperature conversion menu:\n");
 printf("1. celsius to fahrenheit\n");
 printf("Enter your choice(1 or 2):");
 scanf("%d", &choice);

 switch (choice)
 {

case 1:

printf("Enter temperature in celsius:");
scanf("%f", &temperature );
convertedtemperature = (temperature * 9.0/5.0) + 32.0; 
printf("%.2f celsius is equal to %.2f fahrenheit.\n", temperature, connvertedtemperature);
break;

case 2:
printf("enter temperature in fahrenheit:");
scanf("%f", &temperature);
convertedtemperature = (temperature - 32.0) * 5.0/9.0;
printf(%.2f fahrenheit is equal to %.2f celsius.\n", temperature, covertedTemperature);
break;

default:

printf("Invalid choice. please enter 1 or 2.\n");
break;
}

return 0;

}

 

