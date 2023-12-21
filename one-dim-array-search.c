/*
Problem: IT1108_Bai3_5_Tìm kiếm trong mảng 1 chiều
Description
Cho mảng số nguyên A có n phần tử, hãy tìm kiếm xem trong mảng có xuất hiện phần tử x và in ra vị trí đầu tiên và vị trí cuối cùng tìm thấy phần tử x (chỉ số vị trí bắt đầu từ 0)
- Nếu không tìm thấy phần tử x thì in ra: NO
- Nếu chỉ phần tử x chỉ xuất hiện 1 lần ở trong mảng thì in ra 2 số cùng là vị trí tìm thấy (ví dụ: 3 3 - tìm thấy phần tử x ở vị trí thứ 3)
- Nếu phần tử x xuất hiện nhiều hơn 2 lần thì in ra 2 số gồm vị trí đầu tiên và vị trí cuối cùng tìm thấy x (ví dụ: 3, 6 - tìm thấy phẩn tử x ở vị trí thứ 3 và thứ 6)
Input

    Dòng 1 là số nguyên dương n (số lượng phần tử của mảngm n≤10^5) và số nguyên x (|x|≤10^6) là giá trị cần tìm
    Dòng tiếp theo là n số nguyên là các phần tử của mảng (|a[i,j]|≤10^6)

Output:
In ra thông tin như yêu cầu của đầu bài
Ví dụ mẫu:
Input#1
5 3
1 2 3 4 5
Output#1
*/

#include <stdio.h>

int main()
{
    int n, x, first = -1, last = -1;
    scanf("%d %d", &n, &x);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        if (value == x) {
            if (first == -1)
                first = i; // Record the first occurrence
            last = i; // Update the last occurrence
        }
    }

    if (first == -1) {
        printf("NO\n"); // x not found in the array
    } else {
        printf("%d %d\n", first, last); // Print first and last positions
    }

    return 0;
}
