/*
Description
Để làm cộng các số vô cùng lớn (có thể có đến 100 chữ số) người ta xử lí số như là một chuỗi chứa các
kí tự trong phạm vi từ '0' đến '9'). Hãy viết chương trình cộng hai số vô cùng lớn sử dụng stack. Kết quả hiển thị ra màn hình
Input:
123
456
Output:
579

Input:
456
98
Output:
554
*/
#include <stdio.h>
#include <string.h>

#define MAX 101

// Stack structure
typedef struct {
    int top;
    int array[MAX];
} Stack;

// Function to initialize stack
void initStack(Stack* s)
{
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* s)
{
    return s->top == -1;
}

// Check if the stack is full
int isFull(Stack* s)
{
    return s->top == MAX - 1;
}

// Function to push an element to stack
void push(Stack* s, int item)
{
    if (isFull(s))
        return;
    s->array[++s->top] = item;
}

// Function to pop an element from stack
int pop(Stack* s)
{
    if (isEmpty(s))
        return -1;
    return s->array[s->top--];
}

// Function to add two numbers using stack
void addLargeNumbers(char* num1, char* num2)
{
    Stack s1, s2, result;
    initStack(&s1);
    initStack(&s2);
    initStack(&result);

    // Push digits of first number to stack
    for (int i = 0; i < strlen(num1); i++) {
        push(&s1, num1[i] - '0');
    }

    // Push digits of second number to stack
    for (int i = 0; i < strlen(num2); i++) {
        push(&s2, num2[i] - '0');
    }

    int carry = 0;
    while (!isEmpty(&s1) || !isEmpty(&s2) || carry > 0) {
        int sum = carry;
        if (!isEmpty(&s1))
            sum += pop(&s1);
        if (!isEmpty(&s2))
            sum += pop(&s2);
        push(&result, sum % 10);
        carry = sum / 10;
    }

    // Print result
    while (!isEmpty(&result)) {
        printf("%d", pop(&result));
    }
    printf("\n");
}

int main()
{
    char num1[MAX], num2[MAX];

    // Read input numbers as strings
    scanf("%s", num1);
    scanf("%s", num2);

    // Add the numbers
    addLargeNumbers(num1, num2);

    return 0;
}
