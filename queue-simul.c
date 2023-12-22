/*
Problem: Simulation Queue
Description
Perform a sequence of operations over a queue, each element is an integer:

    PUSH v: push a value v into the queue
    POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)

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
1
2
3

Input
PUSH 1
POP
POP
PUSH 4
POP
#
Output
1
NULL
4
*/
#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

// Define a structure for the queue
typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize an empty queue
void initializeQueue(Queue* q)
{
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q)
{
    return (q->front == -1 && q->rear == -1);
}

// Function to check if the queue is full
int isFull(Queue* q)
{
    return (q->rear == MAX_QUEUE_SIZE - 1);
}

// Function to push an element into the queue
void push(Queue* q, int value)
{
    if (isFull(q)) {
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }

    q->items[q->rear] = value;
}

// Function to pop an element from the queue and print it
void pop(Queue* q)
{
    if (isEmpty(q)) {
        printf("NULL\n");
        return;
    }

    int value = q->items[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }

    printf("%d\n", value);
}

int main()
{
    Queue q;
    initializeQueue(&q);

    char command[10];
    int value;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "PUSH") == 0) {
            scanf("%d", &value);
            push(&q, value);
        } else if (strcmp(command, "POP") == 0) {
            pop(&q);
        } else {
            break;
        }
    }

    return 0;
}
