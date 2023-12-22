/*
Problem: Gen k-combinations of 1 2 - n
Description
Given 2 positive integers k and n. Write a program tat generates all k-combinations of 1, 2, ..., n in a lexicographic order.

Example
Input
2 4
Output
1 2
1 3
1 4
2 3
2 4
3 4
*/
#include <stdio.h>

void generateCombinations(int arr[], int n, int k, int index, int current)
{
    if (index == k) {
        for (int i = 0; i < k; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    if (current > n) {
        return;
    }

    arr[index] = current;
    generateCombinations(arr, n, k, index + 1, current + 1);
    generateCombinations(arr, n, k, index, current + 1);
}

int main()
{
    int n, k;
    scanf("%d %d", &k, &n);

    if (k <= n && k >= 0 && n >= 0) {
        int arr[k];
        generateCombinations(arr, n, k, 0, 1);
    } else {
        return 0;
    }

    return 0;
}
