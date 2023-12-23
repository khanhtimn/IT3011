/*
Problem: Add an element at the beginning of a sequence
Description
Given a sequence S of n integers a1, a2, . . ., an. Perform a sequence of operation:

    add_first  v: to add an integer at the beginning of the sequence S

Print the resulting sequence to stdout.

    Input
    Line 1: contains a positive integer n (1 <= n <= 100000)
    Line 2 contains n postive integer a1, a2, ..., an (1 <= ai <= 1000000)
    Each subsequent line (number of lines can be up to 100000)  contains an operation of format above

Output

    Write the resulting sequence, elements are separated by a SPACE character


Example
Input
4
1 2 3 4
add_first 5
add_first 6
add_first 7
#
Output
7 6 5 1 2 3 4
*/
#include <stdio.h>
#include <stdlib.h>

// Define a node for the singly linked list
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void addFirst(Node** head, int value)
{
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Function to print the list
void printList(Node* head)
{
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Function to free the list
void freeList(Node* head)
{
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    int n, i, value;
    char operation[20];

    // Read the initial size of the sequence
    scanf("%d", &n);

    // Create the head of the list
    Node* head = NULL;

    // Read the initial sequence and add to the list
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        addFirst(&head, value);
    }

    // Reverse the list to maintain the initial order
    Node *prev = NULL, *current = head, *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    // Read operations
    while (1) {
        scanf("%s", operation);
        if (strcmp(operation, "#") == 0) {
            break;
        }

        scanf("%d", &value);
        addFirst(&head, value);
    }

    // Print the final sequence
    printList(head);

    // Free the allocated memory
    freeList(head);

    return 0;
}
