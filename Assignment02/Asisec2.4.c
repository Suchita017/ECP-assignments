#include <stdio.h>

int main() {
    int day, month, year, k, j, h;

    printf("Enter day: ");
    scanf("%d", &day);
    printf("Enter month: ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    if (month < 3) {
        month += 12;
        year -= 1;
    }

    k = year % 100;
    j = year / 100;

    h = (day + 2 * month + 3 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    switch (h) {
        case 0:
            printf("The day of the week is Saturday\n");
            break;
        case 1:
            printf("The day of the week is Sunday\n");
            break;
        case 2:
            printf("The day of the week is Monday\n");
            break;
        case 3:
            printf("The day of the week is Tuesday\n");
            break;
        case 4:
            printf("The day of the week is Wednesday\n");
            break;
        case 5:
            printf("The day of the week is Thursday\n");
            break;
        case 6:
            printf("The day of the week is Friday\n");
            break;
    }

    return 0;
}

