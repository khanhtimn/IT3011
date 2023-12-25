/*
Problem: Generate permutations no 2 consecutive even elements
Description
Write a program that generates all permutations of 1, 2, ..., n in a lexicographic order such that there are no 2 consecutive even elements.
Input

    A line contains a positive integer n (2 <= n <= 9)

Output

    Each line contains a permutation, elements a re separated by a SPACE character

Example
Input
4
Output
1 2 3 4
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
3 2 1 4
3 4 1 2
4 1 2 3
4 1 3 2
4 3 1 2
4 3 2 1
*/
#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int isValidPermutation(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] % 2 == 0 && arr[i + 1] % 2 == 0) {
            return 0; // Invalid if two consecutive numbers are even
        }
    }
    return 1; // Valid permutation
}

// Function to find the next lexicographic permutation
int nextPermutation(int arr[], int n)
{
    int i = n - 2;

    // Find the first element which is smaller than its next element
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    // If no such element exists, then this is the last permutation
    if (i < 0) {
        return 0;
    }

    // Find the smallest element on right side of 'i' which is greater than arr[i]
    int j = n - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }

    // Swap arr[i] and arr[j]
    swap(&arr[i], &arr[j]);

    // Reverse the sub-array after i
    int l = i + 1, r = n - 1;
    while (l < r) {
        swap(&arr[l], &arr[r]);
        l++;
        r--;
    }

    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1; // Initialize array with 1, 2, ..., n
    }

    do {
        if (isValidPermutation(arr, n)) {
            for (int i = 0; i < n; ++i) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    } while (nextPermutation(arr, n));

    free(arr);
    return 0;
}
