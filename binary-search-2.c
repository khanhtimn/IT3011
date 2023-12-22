/*
Problem: Tìm kiếm phần tử trong dãy
Description
Viết chương trình nhập 1 số nguyên dương n và sau đó là 1 dãy a gồm n số nguyên.
Sau đó tiếp tục nhập 1 số nguyên dương m và m giá trị nguyên v[0], ..., v[m - 1].
Sau đó lần lượt tìm các giá trị v[0], ..., v[m - 1] trong dãy a rồi xuất kết quả ra màn hình, kết quả cho mỗi lượt tìm kiếm trên 1 dòng.
Kết quả tìm kiếm là 1 nếu tìm thấy hoặc 0 nếu không tìm thấy.
Ví dụ:
Đầu vào:
5
2 1 3 8 6
3
2 5 8
Đầu ra:
1
0
1
*/
#include <stdio.h>
#include <stdlib.h>

// Hàm so sánh để sử dụng cho việc sắp xếp và tìm kiếm nhị phân
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

// Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return 1; // Tìm thấy
        }

        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0; // Không tìm thấy
}

int main()
{
    int n, m;

    // Nhập số nguyên dương n
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    // Khai báo và nhập mảng a gồm n số nguyên
    int a[n];
    printf("Nhap day a gom %d so nguyen: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sắp xếp mảng a
    qsort(a, n, sizeof(int), compare);

    // Nhập số nguyên dương m
    printf("Nhap so nguyen duong m: ");
    scanf("%d", &m);

    // Khai báo và nhập mảng v gồm m số nguyên
    int v[m];
    printf("Nhap %d gia tri nguyen v[0], ..., v[m-1]: ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &v[i]);
    }

    // Tìm kiếm và xuất kết quả
    for (int i = 0; i < m; i++) {
        int found = binarySearch(a, 0, n - 1, v[i]);
        printf("%d\n", found);
    }

    return 0;
}
