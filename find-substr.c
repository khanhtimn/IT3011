/*
Problem: IT3011_C1B10: Tìm kiếm chuỗi con trong một chuỗi
Description
Viết chương trình tìm kiếm chuỗi con trong 1 chuỗi. Yêu cầu là tìm kiếm đếm một chuỗi con xem chuỗi con đó xuất hiện  bao nhiêu lần trong một chuỗi.
Input:
Dòng 1: Chứa chuỗi con cần đếm.
Dòng 2: Chứa chuỗi lớn.
Ouput:
Số lần xuất hiện.
Ví dụ:
Input
te
dai hoc kinh te quoc dan
Output
1
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char substring[100], str[1000];
    int count = 0, i, j, found;

    scanf("%s", substring);
    getchar();
    fgets(str, 1000, stdin);

    int lenSub = strlen(substring);
    int lenStr = strlen(str);

    for (i = 0; i <= lenStr - lenSub; i++) {
        found = 1;
        for (j = 0; j < lenSub; j++) {
            if (str[i + j] != substring[j]) {
                found = 0;
                break;
            }
        }

        if (found == 1)
            count++;
    }

    printf("%d\n", count);

    return 0;
}
