#include <stdio.h>
#include <stdbool.h>

// Helper function to check if a character is in a given string
bool isCharInString(char c, const char *str) {
    while (*str != '\0') {
        if (*str == c) {
            return true;
        }
        str++;
    }
    return false;
}

// Function to remove all occurrences of any character in string1 from string2
void removeChars(char *string2, const char *string1) {
    char *src, *dst;
    
    // Initialize source and destination pointers
    src = dst = string2;
    
    // Traverse the string2
    while (*src != '\0') {
        // If the current character is not in string1, copy it to the destination
        if (!isCharInString(*src, string1)) {
            *dst = *src;
            dst++;
        }
        // Move to the next character in string2
        src++;
    }
    
    // Null-terminate the destination string
    *dst = '\0';
}

int main() {
    char string2[] = "Hello, World!";
    const char *string1 = "ol";  // Characters to remove from string2
    
    printf("Original string2: %s\n", string2);
    
    removeChars(string2, string1);
    
    printf("String2 after removal: %s\n", string2);
    
    return 0;
}

