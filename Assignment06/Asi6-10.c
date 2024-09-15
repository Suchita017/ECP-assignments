#include <stdio.h>

// Function to find the first occurrence of a substring in a string
int findSubstring(const char *str, const char *sub) {
    const char *p1;
    const char *p2;
    const char *p1_advance;
    size_t len_sub = 0;

    // Find length of substring
    for (len_sub = 0; sub[len_sub] != '\0'; len_sub++);

    for (p1 = str; *p1; p1++) {
        p2 = p1;
        p1_advance = sub;

        // Compare substring with the part of the main string
        while (*p2 && *p1_advance && (*p2 == *p1_advance)) {
            p2++;
            p1_advance++;
        }
        
        // If the end of the substring is reached, return the position
        if (!*p1_advance) {
            return p1 - str;
        }
    }
    return -1; // Not found
}

// Function to replace all occurrences of 'find' with 'replace' in 'source'
void findAndReplace(const char *source, const char *find, const char *replace, char *result) {
    int pos;
    size_t findLen = 0;
    size_t replaceLen = 0;
    size_t i = 0;
    size_t j;

    // Find lengths of 'find' and 'replace'
    for (findLen = 0; find[findLen] != '\0'; findLen++);
    for (replaceLen = 0; replace[replaceLen] != '\0'; replaceLen++);
    
    while ((pos = findSubstring(source, find)) != -1) {
        // Copy characters before the found substring
        for (j = 0; j < pos; j++) {
            result[i++] = source[j];
        }
        // Copy the replacement substring
        for (j = 0; j < replaceLen; j++) {
            result[i++] = replace[j];
        }
        // Move the source pointer past the found substring
        source += pos + findLen;
    }
    // Copy remaining characters from source
    while (*source) {
        result[i++] = *source++;
    }
    result[i] = '\0'; // Null-terminate the result string
}

int main() {
    char source[] = "This is test time";
    char find[] = "is";
    char replace[] = "was";
    char result[1024];

    findAndReplace(source, find, replace, result);
    printf("Output: %s\n", result);

    return 0;
}

