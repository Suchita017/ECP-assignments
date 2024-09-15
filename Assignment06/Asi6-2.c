#include <stdio.h>
#include <ctype.h>

// Function to calculate the length of a string
size_t my_strlen(const char *str) {
    const char *s;
    for (s = str; *s; ++s);
    return (s - str);
}

// Function to copy a string from src to dest
char* my_strcpy(char *dest, const char *src) {
    char *d = dest;
    while ((*d++ = *src++));
    return dest;
}

// Function to concatenate src string to the end of dest string
char* my_strcat(char *dest, const char *src) {
    char *d = dest;
    while (*d) d++; // Move to the end of dest
    while ((*d++ = *src++));
    return dest;
}

// Function to compare two strings
int my_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

// Function to perform a case-insensitive comparison of two strings
int my_stricmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2 || tolower((unsigned char)*str1) == tolower((unsigned char)*str2))) {
        str1++;
        str2++;
    }
    return tolower((unsigned char)*str1) - tolower((unsigned char)*str2);
}

// Function to reverse a string
char* my_strrev(char *str) {
    char *start = str;
    char *end = str;
    char temp;

    if (str) {
        while (*end) {
            end++;
        }
        end--;

        while (start < end) {
            temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }
    }
    return str;
}

// Function to find the first occurrence of a character in a string
char* my_strchr(const char *str, int ch) {
    while (*str) {
        if (*str == (char)ch) {
            return

