#include <stdio.h>

int main() {
    int quantity;
    float unitPrice = 5.0, totalPrice, discount;

    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    if (quantity > 50) {
        discount = 0.15;
    } else if (quantity > 30) {
        discount = 0.10;
    } else {
        discount = 0.0;
    }

    totalPrice = quantity * unitPrice * (1 - discount);

    printf("Total price for %d units is Rs %.2f.\n", quantity, totalPrice);

    return 0;
}

