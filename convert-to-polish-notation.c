/*
Problem: C_BASIC_NVTUNG_STACK_Convert2ReversePolishNotation
Description
Cài đặt thuật toán Shunting Yard để chuyển biểu thức toán học biểu diễn dạng infix sang postfis sử dụng stack.
Giới hạn:
1. toán tử chỉ là số nguyên dương chữ số, phạm vi từ 0 đến 9
2. toán hạng: chỉ xét 2 toán hạng '*' và '+', lưu ý thứ tự ưu tiên, phép toán '*' thực hiện trước phép toán '+'
3. Không có ngoặc đơn để thay đổi thứ tự ưu tiên tính toán
Đầu vào: chuỗi chứa biểu thức dạng infix không có khoảng trắng, không chứa khoảng trắng đầu và cuối chuỗi. Số kí tự tối đa của chuỗi là 50 kí tự có nghĩa: ví dụ: 2*3+9
Đầu ra: chuỗi chứa biểu thức dạng postfix, kết quả của việc chuyển đổi, các toán hạng và toán tử cách nhau 01 khoảng trắng, không có khoảng trắng đầu và khoảng trắng cuối. ví dụ: 2 3 * 9 +
Ví dụ 1:
Đầu vào: 2*3+9
Đầu ra: 2 3 * 9 +
Ví dụ 2:
Đầu vào: 2+3*9
Đầu ra: 2 3 9 * +
Ví dụ 3:
Đầu vào: 2*3*4+5
Đầu ra:2 3 4 * * 5 +
Xem thêm về giải thuật tại: https://mathcenter.oxford.emory.edu/site/cs171/shuntingYardAlgorithm/#:~:text=Edsger%20Dijkstra%20developed%20his%20%22Shunting,the%20operators%20in%20the%20expression.
*/
#include <stdio.h>

#define MAX_SIZE 50

// Structure to represent a stack
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Function to initialize an empty stack
void initialize(struct Stack* s)
{
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s)
{
    return s->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack* s, char c)
{
    if (s->top < MAX_SIZE - 1) {
        s->items[++s->top] = c;
    }
}

// Function to pop an item from the stack
char pop(struct Stack* s)
{
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return '\0';
}

// Function to get the precedence of an operator
int precedence(char op)
{
    if (op == '*' || op == '+') {
        return (op == '*') ? 2 : 1;
    }
    return -1; // Invalid operator
}

// Function to convert infix expression to postfix notation
void infixToPostfix(char infix[], char postfix[])
{
    struct Stack stack;
    initialize(&stack);

    int i, j = 0;

    for (i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isdigit(c)) {
            // Operand, copy to the output
            postfix[j++] = c;
            while (isdigit(infix[i + 1])) {
                i++;
                postfix[j++] = infix[i];
            }
            postfix[j++] = ' '; // Separate operands with space
        } else if (c == '*' || c == '+') {
            // Operator
            while (!isEmpty(&stack) && precedence(stack.items[stack.top]) >= precedence(c)) {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' '; // Separate operators with space
            }
            push(&stack, c);
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
        postfix[j++] = ' '; // Separate operators with space
    }

    postfix[j - 1] = '\0'; // Null-terminate the postfix expression
}

int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE * 2]; // Maximum possible size for postfix

    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("%s\n", postfix);

    return 0;
}
