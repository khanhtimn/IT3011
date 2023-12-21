/*
Problem: Sort a sequence of integers
Description
Given a sequence of integers a1, a2, ..., an. Sort the sequence in a non-deccreasing order.
Input

    Line 1: contains an integer n (1 <= n <= 1000000)
    Line 2: a1, a2, ..., an. (0 <= ai <= 100000)

Output
Write the sorted sequence, elements are separated by a SPACE chharacter.
Example
Input
4
1 3 4 2
Output
1 2 3 4
*/

#include <stdio.h>
#include <stdlib.h>

void quickSort(int* arr, int low, int high);
int partition(int* arr, int low, int high);
void swap(int* a, int* b);

int main()
{
    int n;

    // Reading the size of the array
    scanf("%d", &n);

    // Allocating memory for the array
    int* arr = (int*)malloc(n * sizeof(int));

    // Reading the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting the array
    quickSort(arr, 0, n - 1);

    // Printing the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Freeing the allocated memory
    free(arr);

    return 0;
}

void quickSort(int* arr, int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int* arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
