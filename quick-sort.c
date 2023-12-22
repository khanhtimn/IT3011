/*
Problem: Sắp xếp dãy số thực qsort
Description
Viết chương trình nhập vào 1 số n, sau đó nhập vào 1 dãy n số thực, các giá trị số được ngăn cách bởi khoảng trắng.
Sau đó sắp xếp và in ra các số theo thứ tự giảm dần, mỗi giá trị 1 dòng,
các gía trị được làm tròn tới 2 chữ số phần thập phân.
Ví dụ:
Đầu vào:
3
2.3 1.17 3.90
Đầu ra:
3.90
2.30
1.17
*/
#include <stdio.h>

void quickSort(float arr[], int left, int right)
{
    int i = left, j = right;
    float tmp;
    float pivot = arr[(left + right) / 2];

    // Partition
    while (i <= j) {
        while (arr[i] > pivot)
            i++;
        while (arr[j] < pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    // Recursion
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int main()
{
    int n;
    scanf("%d", &n);
    float arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%.2f\n", arr[i]);
    }

    return 0;
}
