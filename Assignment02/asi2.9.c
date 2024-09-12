#include <stdio.h>

int main() {
    int month, year, days;

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            days = 29;
        } else {
            days = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days = 30;
    } else if (month >= 1 && month <= 12) {
        days = 31;
    } else {
        printf("Invalid month.\n");
        return 1;
    }

    printf("Number of days in month %d of year %d is %d.\n", month, year, days);

    return 0;
}

/*
#include <stdio.h>

int main() {
    int month, year, days;

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    if (month == 2) {
        days = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;
    } else {
        days = (month == 4 || month == 6 || month == 9 || month == 11) ? 30 :
               ((month >= 1 && month <= 12) ? 31 : -1);
    }

    if (days == -1) {
        printf("Invalid month.\n");
    } else {
        printf("Number of days in month %d of year %d is %d.\n", month, year, days);
    }

    return 0;
}
*/
