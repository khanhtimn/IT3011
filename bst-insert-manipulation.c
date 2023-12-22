/*
Problem: BST - Insertion and PreOrder Traversal
Description
Given a BST initialized by NULL. Perform a sequence of operations on a BST including:

    insert k: insert a key k into the BST (do not insert if the key k exists)

Input
•Each line contains command under the form: “insert k”
•The input is terminated by a line containing #
Output
•Write the sequence of keys of nodes visited by the pre-order traversal (separated by a SPACE character)
Example
Input
insert 20
insert 10
insert 26
insert 7
insert 15
insert 23
insert 30
insert 3
insert 8
#
Output
20 10 7 3 8 15 26 23 30
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure for the BST
typedef struct node {
    int key;
    struct node *left, *right;
} Node;

// Function to create a new node
Node* newNode(int item)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node with a given key in the BST
Node* insert(Node* node, int key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the (unchanged) node pointer
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

// Main function
int main()
{
    Node* root = NULL;
    char command[10];
    int key;

    while (scanf("%s", command) != EOF) {
        if (command[0] == '#')
            break; // End of input
        if (scanf("%d", &key) != 1)
            break; // Input format error

        // Insert key into BST
        if (root == NULL)
            root = insert(root, key);
        else
            insert(root, key);
    }

    // Perform pre-order traversal
    preOrder(root);

    return 0;
}
