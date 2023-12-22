/*
Problem: stack check
Description
Kiểm tra một chuỗi dấu ngoặc nhập vào xem có hợp lệ hay không (1 là hợp lệ, 0 là không hợp lệ)
VD
INPUT:
[({})]()
OUTPUT:
1
INPUT:
([} {})
OUTPUT:
0
*/
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc ngăn xếp
struct Stack {
    char data;
    struct Stack* next;
};

// Hàm kiểm tra tính hợp lệ của chuỗi dấu ngoặc
int is_valid_expression(const char* expr)
{
    struct Stack* stack = NULL;
    char ch;

    for (int i = 0; expr[i] != '\0'; i++) {
        ch = expr[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            // Đẩy dấu ngoặc mở vào ngăn xếp
            struct Stack* new_node = (struct Stack*)malloc(sizeof(struct Stack));
            new_node->data = ch;
            new_node->next = stack;
            stack = new_node;
        } else if (ch == ')' || ch == ']' || ch == '}') {
            // Kiểm tra nếu ngăn xếp rỗng hoặc dấu ngoặc đóng không phù hợp
            if (stack == NULL) {
                return 0;
            }

            // Kiểm tra tính hợp lệ của cặp dấu ngoặc
            char top = stack->data;
            if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')) {
                // Loại bỏ dấu ngoặc mở khỏi ngăn xếp
                struct Stack* temp = stack;
                stack = stack->next;
                free(temp);
            } else {
                return 0; // Dấu ngoặc không hợp lệ
            }
        }
    }

    // Kiểm tra xem ngăn xếp có trống không sau khi kiểm tra xong không
    return stack == NULL ? 1 : 0;
}

int main()
{
    char expr[100];
    scanf("%s", expr);

    int result = is_valid_expression(expr);

    if (result) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
