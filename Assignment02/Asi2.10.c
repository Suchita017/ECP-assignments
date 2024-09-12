#include<stdio.h>

def categorize_character(c):
    if len(c) != 1:
        return "Invalid input: Please enter a single character."

    ascii_value = ord(c)

    if 65 <= ascii_value <= 90:
        return "UPPERCASE: c is an uppercase letter"
    elif 97 <= ascii_value <= 122:
        return "LOWERCASE: c is a lowercase letter"
    elif 48 <= ascii_value <= 57:
        return "DIGIT: c is a digit"
    elif ascii_value == 32 or ascii_value == 9 or ascii_value == 13 or ascii_value == 10:
        return "SPACE: c is a space, tab, carriage return, or new line"
    else:
        return "OTHER: Not listed above in c"

char_input = input("Enter a single character: ")
result = categorize_character(char_input)
print(result)

