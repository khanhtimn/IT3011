/*
Problem: Max Subsequence No 2 adjacent elements selected
Description
Given a sequence of positive integers a1, a2,  . . ., an. Select the subset of elements such that the sum is maximal and no 2 adjacent elements are selected.
Input

    Line 1: contains a positive integer n (1 <= n <= 100000)
    Line 2: contains a1, a2,  . . ., an (1 <= ai <= 1000)

Output

    Write the sum of elements of the subseq found

Example
Input
5
2 5 4 6 7
Output
13

Explanation the subset found is: {2, 4, 7}
*/
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two numbers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to find the maximum sum of non-adjacent elements
int findMaxSum(int arr[], int n)
{
    int incl = arr[0]; // Maximum sum including the first element
    int excl = 0; // Maximum sum excluding the first element
    int excl_new; // Temporary variable to store new excl

    for (int i = 1; i < n; i++) {
        // Current max excluding i
        excl_new = max(incl, excl);

        // Current max including i
        incl = excl + arr[i];
        excl = excl_new;
    }

    // Return max of incl and excl
    return max(incl, excl);
}

int main()
{
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", findMaxSum(arr, n));

    free(arr);
    return 0;
}
