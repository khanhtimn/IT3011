/*
Problem: Letter frequency in a string
Description
Write a program that gets an string from the user (ends with ‘\n’) and displays the number of times each letter appears in it.
input:
- Line 1 contains a string , for example "Hello, world!"
output: the number of times each letter appear in the format <LETTER> <TIMES>, each letter a line, for example
d 1
e 1
h 1
l 3
o 2
r 1
w 1
*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

int main()
{
    char str[MAX_STRING_LENGTH];
    int freq[26] = { 0 }; // Frequency array for each letter

    // Read input
    fgets(str, MAX_STRING_LENGTH, stdin);

    // Count frequency of each letter
    for (int i = 0; i < strlen(str); i++) {
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++;
        }
    }

    // Display results
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c %d\n", i + 'a', freq[i]);
        }
    }

    return 0;
}
