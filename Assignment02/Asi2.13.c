#include <stdio.h>

int main() {
    float x, y;

    // Input coordinates
    printf("Enter the x-coordinate: ");
    scanf("%f", &x);
    printf("Enter the y-coordinate: ");
    scanf("%f", &y);

    // Determine the quadrant or special case
    if (x == 0 && y == 0) {
        printf("The point is at the origin.\n");
    } else if (x == 0) {
        if (y > 0) {
            printf("The point is on the positive y-axis.\n");
        } else {
            printf("The point is on the negative y-axis.\n");
        }
    } else if (y == 0) {
        if (x > 0) {
            printf("The point is on the positive x-axis.\n");
        } else {
            printf("The point is on the negative x-axis.\n");
        }
    } else {
        if (x > 0 && y > 0) {
            printf("The point is in the first quadrant.\n");
        } else if (x < 0 && y > 0) {
            printf("The point is in the second quadrant.\n");
        } else if (x < 0 && y < 0) {
            printf("The point is in the third quadrant.\n");
        } else if (x > 0 && y < 0) {
            printf("The point is in the fourth quadrant.\n");
        }
    }

    return 0;
}

