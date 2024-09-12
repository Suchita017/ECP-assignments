#include <stdio.h>

void printStarPattern(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printNumberPattern1(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printNumberPattern2(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= i; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void printStarPatternDescending(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printCharacterPattern1(int n) {
    char startChar = 'A';
    for (int i = 0; i < n; i++) {
        char ch = startChar + i;
        for (char c = startChar; c <= ch; c++) {
            printf("%c ", c);
        }
        printf("\n");
    }
}

void printCharacterPattern2(int n) {
    for (int i = n; i >= 1; i--) {
        char startChar = 'A' + (n - i);
        for (char ch = startChar; ch < 'A' + n; ch++) {
            printf("%c ", ch);
        }
        printf("\n");
    }
}

void printCharacterPattern3(int n) {
    for (int i = n; i >= 1; i--) {
        char startChar = 'A' + (n - i);
        char endChar = 'A' + (n - 1);
        for (char c = startChar; c <= endChar; c++) {
            printf("%c ", c);
        }
        for (char c = endChar - 1; c >= startChar; c--) {
            printf("%c ", c);
        }
        printf("\n");
    }
}

void printCharacterPattern4(int n) {
    char endChar = 'A' + (n - 1);
    for (int i = 0; i < n; i++) {
        for (char c = 'A' + i; c <= endChar; c++) {
            printf("%c ", c);
        }
        printf("\n");
    }
}

void printCharacterPattern5(int n) {
    char startChar = 'A';
    for (int i = 0; i < n; i++) {
        for (char c = startChar; c < startChar + n; c++) {
            printf("%c ", c);
        }
        printf("\n");
        startChar++;
        n--;
    }
}

int main() {
    int n;

    // Star Pattern
    printf("Star Pattern:\n");
    n = 5;
    printStarPattern(n);

    // Number Pattern 1
    printf("\nNumber Pattern 1:\n");
    n = 5;
    printNumberPattern1(n);

    // Number Pattern 2
    printf("\nNumber Pattern 2:\n");
    n = 5;
    printNumberPattern2(n);

    // Star Pattern Descending
    printf("\nStar Pattern Descending:\n");
    n = 5;
    printStarPatternDescending(n);

    // Character Pattern 1
    printf("\nCharacter Pattern 1:\n");
    n = 4;
    printCharacterPattern1(n);

    // Character Pattern 2
    printf("\nCharacter Pattern 2:\n");
    n = 4;
    printCharacterPattern2(n);

    // Character Pattern 3
    printf("\nCharacter Pattern 3:\n");
    n = 7;
    printCharacterPattern3(n);

    // Character Pattern 4
    printf("\nCharacter Pattern 4:\n");
    n = 4;
    printCharacterPattern4(n);

    // Character Pattern 5
    printf("\nCharacter Pattern 5:\n");
    n = 4;
    printCharacterPattern5(n);

    return 0;
}

