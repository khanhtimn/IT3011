/*
Problem: Binary sequences generation without consecutive 11
Description
Given an integer n, write a program that generates all binary sequences without consecutive 11 in a lexicographic order.
Input

    Line 1: contains an integer n (1 <= n <= 20)

Output
Write binary sequences in a lexicographic order, each sequence in a line
Example
Input
3
Output
000
001
010
100
101
*/
#include <stdio.h>

void generateSequences(char* str, int n, int pos, char lastAdded)
{
    // Base case: if the current length equals n, print the string
    if (pos == n) {
        str[pos] = '\0';
        printf("%s\n", str);
        return;
    }

    // Add '0' and recurse
    str[pos] = '0';
    generateSequences(str, n, pos + 1, '0');

    // Add '1' only if the last added character is not '1'
    if (lastAdded != '1') {
        str[pos] = '1';
        generateSequences(str, n, pos + 1, '1');
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    char str[n + 1]; // +1 for the null terminator
    generateSequences(str, n, 0, '0'); // Start with '0' as the last added character

    return 0;
}
