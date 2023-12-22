/*
Problem: BST: Build the BST from pre-order sequence of nodes
Description
Given a binary search tree T in which the keys of nodes are distinct positive integers. The sequence of keys visited when traversing T in a pre-order principle is a1, a2, ..., an. Compute the sequence of keys visited when traversing T in a post-order principal.

Input

    Line 1: contains a positive integer n (1 <= n <= 50000)
    Line 2: contains a sequence of distinct positive integer a1, a2, ..., an (1 <= ai <= 1000000)


Output

    Write the sequence of keys visited when traversing T in a post-order principal (elements are separated by a SPACE character) if the binary search tree exists, and write NULL, otherwise.


Example
Input
11
10 5 2 3 8 7 9 20 15 18 40
Output
3 2 7 9 8 5 18 15 40 20 10


Example
Input
11
10 5 2 3 8 7 9 20 15 18 4
Output
NULL
*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left, *right;
} Node;

// Function to create a new node
Node* newNode(int key)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a node in the BST constructed from the pre-order traversal
Node* insert(Node* node, int pre[], int* preIndex, int min, int max, int size)
{
    // Base case
    if (*preIndex >= size)
        return NULL;

    Node* root = NULL;

    // If the current element of pre[] is in range, then only it is part of the current subtree
    int key = pre[*preIndex];
    if (key > min && key < max) {
        // Allocate memory for root of this subtree and increment *preIndex
        root = newNode(key);
        *preIndex = *preIndex + 1;

        if (*preIndex < size) {
            // Construct the subtree under root
            root->left = insert(root, pre, preIndex, min, key, size);
            root->right = insert(root, pre, preIndex, key, max, size);
        }
    }

    return root;
}

// Function for post-order traversal of BST
void postOrder(Node* node)
{
    if (node == NULL)
        return;

    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->key);
}

// Main function to test above functions
int main()
{
    int n;
    scanf("%d", &n);

    int pre[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }

    int preIndex = 0;
    Node* root = insert(NULL, pre, &preIndex, INT_MIN, INT_MAX, n);

    // If the entire pre[] array hasn't been used, then the given sequence can't form a BST
    if (preIndex != n) {
        printf("NULL\n");
    } else {
        postOrder(root);
        printf("\n");
    }

    return 0;
}
