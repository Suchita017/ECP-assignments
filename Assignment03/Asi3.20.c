#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}


int isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int digits = 0;
    
  
    while (originalNum != 0) {
        digits++;
        originalNum /= 10;
    }
    
    originalNum = num;
    
    
    while (originalNum != 0) {
        int digit = originalNum % 10;
        sum += pow(digit, digits);
        originalNum /= 10;
    }
    
    return sum == num;
}

int main() {
    
    printf("Prime numbers between 1 and 100:\n");
    for (int i = 2; i <= 100; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("Armstrong numbers between 1 and 500:\n");
    for (int i = 1; i <= 500; i++) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

