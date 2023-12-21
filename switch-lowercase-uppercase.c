/*
Problem: Chuyển chuỗi ký tự thường sang hoa, còn hoa sang thường
Description
Cho đầu vào là chuỗi ký tự kích thước tối đa 30. Chuyển chuỗi ký tự đầu vào, chữ hoa sang chữ thường, thường sang hoa

INPUT
DhBk
OUTPUT
dHbK
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 30

void swapCase(char* str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            // Convert lowercase to uppercase
            str[i] = str[i] - 'a' + 'A';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            // Convert uppercase to lowercase
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

int main()
{
    char str[MAX_SIZE];

    fgets(str, MAX_SIZE, stdin); // Reads string from input
    str[strcspn(str, "\n")] = 0; // Remove newline character if exists

    swapCase(str);

    printf("%s\n", str);
    return 0;
}
