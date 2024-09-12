#include <stdio.h>

int main() {
    int year, days;

    printf("Enter a year: ");
    scanf("%d", &year);

    if ((year % 4 == 0) && (year % 100 != 0)) {
        days = 366;
    } else {
        if (year % 400 == 0) {
            days = 366;
        } else {
            days = 365;
        }
    }

    printf("Number of days in the year %d is %d.\n", year, days);

    return 0;
}

