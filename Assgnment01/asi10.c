#include <stdio.h>
#include <math.h>

int main() 
{

    double a1 = 3, b1 = 4, c1 = 5;
    double a2 = 1, b2 = 2, c2 = 3;
    double a3 = 1, b3 = 2, c3 = 4;

    {
    double a = a1, b = b1, c = c1;
    double s = (a + b + c) / 2.0;  
	double perimeter = a + b + c;  
    double area = squreroot(s * (s - a) * (s - b) * (s - c));  

        printf("For sides %.1f, %.1f, %.1f:\n", a, b, c);
        printf("Perimeter: %.2f\n", perimeter);
        printf("Area: %.2f\n", area);
        printf("\n");
    }

  
    {
	double a = a2, b = b2, c = c2;
    double s = (a + b + c) / 2.0;  
    double perimeter = a + b + c;  
    double area = (a + b > c && a + c > b && b + c > a) ? squreroot (s * (s - a) * (s - b) * (s - c)) : 0;  

        printf("For sides %.1f, %.1f, %.1f:\n", a, b, c);
        printf("Perimeter: %.2f\n", perimeter);
        printf("Area: %.2f\n", area);
        printf("\n");
    }

    
    {
        double a = a3, b = b3, c = c3;
        double s = (a + b + c) / 2.0;  
        double perimeter = a + b + c;  
        double area = (a + b > c && a + c > b && b + c > a) ? sqrt(s * (s - a) * (s - b) * (s - c)) : 0;  

        printf("For sides %.1f, %.1f, %.1f:\n", a, b, c);
        printf("Perimeter: %.2f\n", perimeter);
        printf("Area: %.2f\n", area);
        printf("\n");
    }

    return 0;
}

