#include <stdio.h>
#include <string.h>

void numberToWords(int num, char *words);

// Function to convert a number into words (up to 999,999,999,999)
void numberToWords(int num, char *words) {
    if (num == 0) {
        strcpy(words, "Zero");
        return;
    }

    // Arrays for word representation
    const char *belowTwenty[] = {
        "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
        "Eighteen", "Nineteen"
    };
    const char *tens[] = {
        "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };
    const char *thousands[] = {
        "", "Thousand", "Million", "Billion"
    };

    // Helper function to convert numbers less than 1000
    void convertLessThanThousand(int num, char *str) {
        if (num >= 100) {
            strcat(str, belowTwenty[num / 100]);
            strcat(str, " Hundred ");
            num %= 100;
        }
        if (num >= 20) {
            strcat(str, tens[num / 10 - 2]);
            strcat(str, " ");
            num %= 10;
        }
        if (num > 0) {
            strcat(str, belowTwenty[num]);
        }
    }

    char result[1024] = "";
    int chunkIndex = 0;

    // Process each chunk of 1000
    for (int i = 0; num > 0; i++) {
        int chunk = num % 1000;
        if (chunk > 0) {
            char chunkWords[512] = "";
            convertLessThanThousand(chunk, chunkWords);
            if (chunkIndex > 0) {
                strcat(chunkWords, " ");
                strcat(chunkWords, thousands[chunkIndex]);
            }
            strcat(chunkWords, " ");
            strcat(chunkWords, result);
            strcpy(result, chunkWords);
        }
        num /= 1000;
        chunkIndex++;
    }

    // Copy the final result to words
    strcpy(words, result);
}

int main() {
    int number = 123456789;
    char words[1024];
    
    numberToWords(number, words);
    printf("The number %d in words is: %s\n", number, words);

    return 0;
}

