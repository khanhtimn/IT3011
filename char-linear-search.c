/*
Problem: CBASIC_NVTung_Search_LinearSearch
Description
Viết hàm search sử dụng tìm kiếm tuần tự để chạy được chương trình chính sau:
int main() {
   char key[] = "D";
phoneAddr_t a[MAX_ELEMENT] = {{"A", "1", "1@"},
                                 {"B", "2", "2@"},
                                 {"C", "3", "3@"},
                                 {"D", "4", "4@"},
                                 {"E", "5", "5@"}};
printf("Search of %s returns %d\n", key, search(a, 5, key));
return 0;
}

Ví dụ 1:
Input: A
Output: 0
Ví dụ 2:
Input: D
Output: 3
*/
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENT 5

typedef struct {
    char name[50];
    char phone[10];
    char email[50];
} phoneAddr_t;

int search(phoneAddr_t a[], int size, char key[])
{
    for (int i = 0; i < size; i++) {
        if (strcmp(a[i].name, key) == 0) {
            return i;
        }
    }
    return -1;
}

int main()
{
    phoneAddr_t a[MAX_ELEMENT] = { { "A", "1", "1@" },
        { "B", "2", "2@" },
        { "C", "3", "3@" },
        { "D", "4", "4@" },
        { "E", "5", "5@" } };

    char key[2]; // Ký tự tìm kiếm + ký tự kết thúc chuỗi '\0'
    printf("Enter a character to search: ");
    scanf("%1s", key); // Đọc một ký tự từ bàn phím

    printf("Search of %s returns %d\n", key, search(a, 5, key));
    return 0;
}
