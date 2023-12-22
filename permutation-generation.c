/*
Problem: Permutation generation
Description
Given an integer n, write a program to generate all permutations of 1, 2, ..., n in a lexicalgraphic order (elements of a permutation are separated by a SPACE character).
Example
Input
3
Output
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
#include <stdbool.h>
#include <stdio.h>

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(int* a, int start, int end)
{
    while (start < end) {
        swap(&a[start], &a[end]);
        start++;
        end--;
    }
}

bool nextPermutation(int* a, int n)
{
    int i = n - 2;
    while (i >= 0 && a[i] >= a[i + 1]) {
        i--;
    }

    if (i < 0) {
        return false;
    }

    int j = n - 1;
    while (a[j] <= a[i]) {
        j--;
    }

    swap(&a[i], &a[j]);
    reverse(a, i + 1, n - 1);
    return true;
}

void printArray(int* a, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    do {
        printArray(arr, n);
    } while (nextPermutation(arr, n));

    return 0;
}
