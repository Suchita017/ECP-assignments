#include <stdio.h>

void removeChar(char *str, char charToRemove) {
    char *src, *dst;
    
    // Initialize source and destination pointers
    src = dst = str;
    
    // Traverse the string
    while (*src != '\0') {
        // If the current character is not the one to remove, copy it to the destination
        if (*src != charToRemove) {
            *dst = *src;
            dst++;
        }
        // Move to the next character in the source string
        src++;
    }
    
    // Null-terminate the destination string
    *dst = '\0';
}

int main() {
    char str[] = "Hello, World!";
    char charToRemove = 'o';
    
    printf("Original string: %s\n", str);
    
    removeChar(str, charToRemove);
    
    printf("String after removal: %s\n", str);
    
    return 0;
}

