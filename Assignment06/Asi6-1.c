#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string (since strrev() is not standard in C)
void strrev(char *str) {
    int len = strlen(str);
    int i;
    char temp;
    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to perform a case-insensitive comparison (similar to stricmp())
int stricmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && tolower((unsigned char)*s1) == tolower((unsigned char)*s2)) {
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

int main() {
    char str1[50], str2[50], result[100];
    char *token;
    
    // Example for strlen()
    strcpy(str1, "Hello, World!");
    printf("Length of str1: %lu\n", strlen(str1));

    // Example for strcpy()
    strcpy(str2, str1);
    printf("str2 after strcpy: %s\n", str2);

    // Example for strcat()
    strcat(result, "Prefix ");
    strcat(result, str1);
    printf("result after strcat: %s\n", result);

    // Example for strcmp()
    printf("strcmp(str1, str2): %d\n", strcmp(str1, str2));

    // Example for stricmp()
    printf("stricmp(str1, str2): %d\n", stricmp(str1, str2));

    // Example for strrev()
    strrev(str1);
    printf("str1 after strrev: %s\n", str1);
    
    // Example for strchr()
    char *ch_ptr = strchr(str1, 'W');
    if (ch_ptr) {
        printf("Character 'W' found at position: %ld\n", ch_ptr - str1);
    } else {
        printf("Character 'W' not found.\n");
    }

    // Example for strstr()
    char *sub_str_ptr = strstr(str1, "World");
    if (sub_str_ptr) {
        printf("Substring 'World' found at position: %ld\n", sub_str_ptr - str1);
    } else {
        printf("Substring 'World' not found.\n");
    }

    // Example for strncpy()
    strncpy(result, str1, 5);
    result[5] = '\0'; // Ensure null termination
    printf("result after strncpy: %s\n", result);

    // Example for strncat()
    strncat(result, " appended", 4); // Append first 4 characters
    printf("result after strncat: %s\n", result);

    // Example for strncmp()
    printf("strncmp(str1, str2, 5): %d\n", strncmp(str1, str2, 5));

    // Example for strtok()
    char str3[] = "This is a test";
    token = strtok(str3, " ");
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}

