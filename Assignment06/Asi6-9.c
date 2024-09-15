#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find and replace all occurrences of a substring
void findAndReplace(char *source, const char *find, const char *replace, char *result) {
    char *pos;
    size_t findLen = strlen(find);
    size_t replaceLen = strlen(replace);
    size_t srcLen = strlen(source);
    char temp[1024];
    size_t tempLen;
    
    // Initialize result
    result[0] = '\0';

    while ((pos = strstr(source, find)) != NULL) {
        // Copy part before the 'find' substring
        strncpy(temp, source, pos - source);
        temp[pos - source] = '\0';
        strcat(result, temp);

        // Append the 'replace' substring
        strcat(result, replace);

        // Move the source pointer past the 'find' substring
        source = pos + findLen;
    }

    // Append the remaining part of the source string
    strcat(result, source);
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

