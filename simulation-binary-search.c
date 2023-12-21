/*
Problem: Simulation binary search
Description
Given a sequence of n integers a1, a2, ..., an. Perform a sequence of queries under the form:
check k: return 1 if k exists in the sequence, and return 0, otherwise

Input

    Line 1: contains a positive integer n (1 <= n <= 100000)
    Line 2: contains a1,a2, ..., an (1 <= ai <= 1000000)
    Each subsequent line contains a query
    The input is terminated with a line containing #


Output
Write in each line the result of the corresponding query of the input

Example
Input
5
1 3 3 3 4
check 3
check 3
check 10
check 5
check 8
#

Output
1
1
0
0
0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two integers for qsort
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

// Binary search function
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return 1; // Element found
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return 0; // Element not found
}

int main()
{
    int n;
    scanf("%d", &n);

    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    char query[10];
    int k;

    // Process queries
    while (1) {
        scanf("%s", query);
        if (query[0] == '#')
            break;

        if (strcmp(query, "check") == 0) {
            scanf("%d", &k);
            printf("%d\n", binarySearch(arr, 0, n - 1, k));
        }
    }

    free(arr); // Free allocated memory
    return 0;
}
