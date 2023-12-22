/*
Problem: Simulation Stack
Description
Perform a sequence of operations over a stack, each element is an integer:

    PUSH v: push a value v into the stack
    POP: remove an element out of the stack and print this element to stdout (print NULL if the stack is empty)

Input
Each line contains a command (operration) of type

    PUSH  v
    POP

Output

    Write the results of POP operations (each result is written in a line)

Example
Input
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#
Output
3
2
5
*/
#include <stdio.h>

// Define the stack data structure
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Initialize the stack
void initializeStack(Stack* stack)
{
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* stack)
{
    return (stack->top == -1);
}

// Check if the stack is full
int isFull(Stack* stack)
{
    return (stack->top == MAX_SIZE - 1);
}

// Push an element onto the stack
void push(Stack* stack, int value)
{
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
    }
}

// Pop an element from the stack and print it
int pop(Stack* stack)
{
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return -1; // Stack is empty
}

int main()
{
    Stack stack;
    initializeStack(&stack);

    char operation[10];
    int value;

    while (scanf("%s", operation) != EOF) {
        if (strcmp(operation, "PUSH") == 0) {
            scanf("%d", &value);
            push(&stack, value);
        } else if (strcmp(operation, "POP") == 0) {
            int poppedValue = pop(&stack);
            if (poppedValue != -1) {
                printf("%d\n", poppedValue);
            } else {
                printf("NULL\n");
            }
        }
    }

    return 0;
}
