/*
Problem: Basic queries on array
Description
Given a sequence of integers a1, a2, ..., an. Perform a sequence of queries over this sequence including:

    find-max: return the maximum element of the given sequence
    find-min: return the minimum element of the given sequence
    sum: return the sum of the elements of the given sequence
    find-max-segment i j: return the maximum element of the subsequence from index i to index j (i <= j)


Input

    The first block contains the information about the given sequence with the following format:
    Line 1: contains a positive integer n (1 <= n <= 10000)
    Line 2: contains n integers a1, a2, ..., an (-1000 <= ai <= 1000)
    The first block is terminated by a character *
    The second block contains a sequence of queries defined above, each query is in a line. The second block is terminated a 3 characters ***


Output

    Write the result of each query in a corresponding line


Example
Input
5
1 4 3 2 5
*
find-max
find-min
find-max-segment 1 3
find-max-segment 2 5
sum
***

Output
5
1
4
5
15
*/

#include <limits.h>
#include <stdio.h>
#include <string.h>

void findMaxMinSum(int arr[], int n, int* max, int* min, long long* sum)
{
    *max = INT_MIN;
    *min = INT_MAX;
    *sum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > *max)
            *max = arr[i];
        if (arr[i] < *min)
            *min = arr[i];
        *sum += arr[i];
    }
}

int findMaxSegment(int arr[], int i, int j)
{
    int max = INT_MIN;
    for (int k = i; k <= j; ++k) {
        if (arr[k] > max)
            max = arr[k];
    }
    return max;
}

int main()
{
    int n, arr[10000], max, min;
    long long sum;
    char query[50];

    // Read the sequence
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    // Skip to the end of the line after the last number
    while (getchar() != '\n')
        ;

    // Pre-compute max, min, and sum
    findMaxMinSum(arr, n, &max, &min, &sum);

    // Process queries
    while (1) {
        scanf("%s", query);
        if (strcmp(query, "***") == 0)
            break; // End of queries

        if (strcmp(query, "find-max") == 0) {
            printf("%d\n", max);
        } else if (strcmp(query, "find-min") == 0) {
            printf("%d\n", min);
        } else if (strcmp(query, "sum") == 0) {
            printf("%lld\n", sum);
        } else if (strncmp(query, "find-max-segment", 16) == 0) {
            int i, j;
            scanf("%d %d", &i, &j);
            printf("%d\n", findMaxSegment(arr, i - 1, j - 1)); // Adjusting index to 0-based
        }
    }

    return 0;
}
