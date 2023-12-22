/*
Problem: BST Creation and Query about PreOrder and PostOrder Traversal
Description
Each node of a Binary Search Tree (BST) T has a key (keys of nodes must be all different).
Perform a sequence of operations on a Binary Search Tree T (starting from empty BST) including:

    insert k: insert a new node having key = k into T
    preorder: print (in a new line) the sequence of keys of nodes of T visited by a Pre-Order traversal (elements are separated by a SPACE character)
    postorder: print (in a new line) the sequence of keys of nodes of T visited by a Post-Order traversal (elements are separated by a SPACE character)


Input

    Each line contains a command of three above format
    The input is terminated by a line containing #

Output

    Write the information of preorder, postorder commands described above


Example
Input
insert 5
insert 9
insert 2
insert 1
preorder
insert 8
insert 5
insert 3
postorder
#

Output
5 2 1 9
1 3 2 8 9 5
*/
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

// Function to insert a node into the BST
Node* insert(Node* node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

// Function for pre-order traversal of BST
void preOrder(Node* root)
{
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function for post-order traversal of BST
void postOrder(Node* root)
{
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

int main()
{
    Node* root = NULL;
    char command[10];
    int key;

    while (scanf("%s", command) != EOF) {
        if (command[0] == '#')
            break; // End of input

        if (strcmp(command, "insert") == 0) {
            if (scanf("%d", &key) == 1) {
                root = insert(root, key);
            }
        } else if (strcmp(command, "preorder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(command, "postorder") == 0) {
            postOrder(root);
            printf("\n");
        }
    }

    return 0;
}
