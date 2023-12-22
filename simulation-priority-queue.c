/*
Problem: Simmulation Priority Queue
Description
A Database D stores elements which are positive integers. Perform a sequence of operations over D including:

    PUSH e: add the element e to D (e is a positive integer)
    POP: remove the element having smallest value out of D and return this element


Input

    Each line contain the information about one operation (the format is described above)

The input is terminated by a line containing the character #

Output

    Write the result of the POP operation on separate lines


Example
Input
PUSH 10
PUSH 4
PUSH 1
PUSH 8
PUSH 7
POP
PUSH 2
PUSH 9
POP
POP
POP
#

Output
1
2
4
7
*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int* priorityQueue;
int capacity = 8; // Initial capacity
int size = 0;

void resizePriorityQueue()
{
    capacity *= 2;
    priorityQueue = realloc(priorityQueue, capacity * sizeof(int));
    if (!priorityQueue) {
        fprintf(stderr, "Failed to resize priority queue.\n");
        exit(EXIT_FAILURE);
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(int element)
{
    if (size == capacity) {
        resizePriorityQueue();
    }

    priorityQueue[size] = element;
    int current = size++;

    while (current != 0 && priorityQueue[current] < priorityQueue[(current - 1) / 2]) {
        swap(&priorityQueue[current], &priorityQueue[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

int pop()
{
    if (size <= 0) {
        return INT_MIN;
    }

    int root = priorityQueue[0];
    priorityQueue[0] = priorityQueue[--size];
    int current = 0;

    while (1) {
        int smallest = current;
        int leftChild = 2 * current + 1;
        int rightChild = 2 * current + 2;

        if (leftChild < size && priorityQueue[leftChild] < priorityQueue[smallest])
            smallest = leftChild;
        if (rightChild < size && priorityQueue[rightChild] < priorityQueue[smallest])
            smallest = rightChild;

        if (smallest != current) {
            swap(&priorityQueue[current], &priorityQueue[smallest]);
            current = smallest;
        } else {
            break;
        }
    }

    return root;
}

int main()
{
    priorityQueue = malloc(capacity * sizeof(int));
    if (!priorityQueue) {
        return 0;
    }

    char command[20];
    int number;

    while (1) {
        scanf("%s", command);
        if (command[0] == '#')
            break;

        if (command[1] == 'U') { // PUSH command
            scanf("%d", &number);
            push(number);
        } else if (command[1] == 'O') { // POP command
            int result = pop();
            if (result != INT_MIN)
                printf("%d\n", result);
        }
    }

    free(priorityQueue);
    return 0;
}
