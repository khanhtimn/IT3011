/*
Problem: Stack add big numbers
Description
Tính tổng hai số lớn nhập vào từ bàn phím (giả sử số thứ nhất lớn hơn). Chỉ sử dụng ngăn xếp, không sử dụng mảng/xâu.
VD:
INPUT:
1234
123
OUTPUT:
1357
*/
#include <stdio.h>
#include <stdlib.h>

// Define a structure for stack node
typedef struct stackNode {
    int data;
    struct stackNode* next;
} StackNode;

// Utility function to create a new stack node
StackNode* newNode(int data)
{
    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Checks if the stack is empty
int isEmpty(StackNode* root)
{
    return !root;
}

// Push an item onto the stack
void push(StackNode** root, int data)
{
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

// Pop an item from the stack
int pop(StackNode** root)
{
    if (isEmpty(*root))
        return -1;
    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to add two numbers using stack
void addNumbers(StackNode* first, StackNode* second)
{
    int carry = 0, sum;
    StackNode* result = NULL;

    while (first != NULL || second != NULL || carry != 0) {
        int firstNum = isEmpty(first) ? 0 : pop(&first);
        int secondNum = isEmpty(second) ? 0 : pop(&second);

        sum = firstNum + secondNum + carry;
        carry = sum / 10;
        push(&result, sum % 10);
    }

    // Print the result
    while (!isEmpty(result)) {
        printf("%d", pop(&result));
    }
    printf("\n");
}

// Function to read number and push its digits onto a stack
void readNumber(StackNode** root)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            push(root, c - '0');
        }
    }
}

int main()
{
    StackNode* firstNumber = NULL;
    StackNode* secondNumber = NULL;

    readNumber(&firstNumber);

    readNumber(&secondNumber);

    addNumbers(firstNumber, secondNumber);

    return 0;
}
