/*
Problem: Sort Strings
Description
Given a sequence of strings S1, S2, . . ., Sn. Sort the given sequence in non-decreasing order.

Input

    Line 1: contains a positive integer n (1 <= n <= 100000)
    Line i+1 (i = 1, 2, ..., n): contains Si


Output

    Write in each line a string in the sorted sequence


Example
Input
10
O0001
Z002
R003
R00004
P05
P00006
T0007
X08
N09
I010

Output
I010
N09
O0001
P00006
P05
R00004
R003
T0007
X08
Z002
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 101

int compareStrings(const void* a, const void* b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}

int main()
{
    int n;
    scanf("%d", &n);

    // Allocate memory for string pointers
    char** strings = (char**)malloc(n * sizeof(char*));
    if (strings == NULL) {
        return 1;
    }

    // Read strings
    for (int i = 0; i < n; i++) {
        strings[i] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
        if (strings[i] == NULL) {
            return 1;
        }
        // printf("%d: ", i + 1);
        scanf("%s", strings[i]);
    }

    // Sort the strings
    qsort(strings, n, sizeof(char*), compareStrings);

    // Print sorted strings
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]); // Free each string
    }

    // Free the array of pointers
    free(strings);

    return 0;
}
