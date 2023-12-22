/*
Problem: Sắp xếp dãy chuỗi ký tự
Description
Viết chương trình nhập vào 1 số nguyên dương n,
sau đó nhập vào n dòng (không quá 100 ký tự), rồi sắp xếp các dòng theo thứ tự bảng mã ASCII.
Rồi xuất kết quả ra màn hình.
Ví dụ:
Đầu vào:
5
aaaa
aa bbbb
ccc cccc
bcbcb ddd
cbb bccc
Đầu ra:
aa bbbb
aaaa
bcbcb ddd
cbb bccc
ccc cccc
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char** arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    char** L = (char**)malloc(n1 * sizeof(char*));
    char** R = (char**)malloc(n2 * sizeof(char*));

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(char** arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar(); // To consume the newline character after reading n

    // Dynamic allocation for array of strings
    char** strings = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        strings[i] = (char*)malloc(101 * sizeof(char));
        fgets(strings[i], 101, stdin);
        strings[i][strcspn(strings[i], "\n")] = 0; // Removing the newline character
    }

    // Sorting the strings using mergeSort
    mergeSort(strings, 0, n - 1);

    // Printing the sorted strings
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]); // Freeing each string
    }

    free(strings); // Freeing the array of strings

    return 0;
}
