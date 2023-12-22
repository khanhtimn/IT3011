/*
Problem: Check if a given binary tree is a BST
Description
Each node of a binary tree has a field key which is the key of the node. Build a binary tree and check if the tree is a binary search tree (BST), and compute the sum of keys of nodes of the given tree (keys of the nodes are distinct and in the range 1, 2, …, 105)
Input
•Line 1 contains MakeRoot u: make the root of the tree having id = u
•Each subsequent line contains: AddLeft or AddRightcommands with the format
•AddLeft u v: create a node having id = u, add this node as a left-child of the node with id = v (if not exists)
•AddRight u v: create a node having id = u, add this node as a right-child of the node with id = v (if not exists)
•The last line contains * which marks the end of the input
Output
•Write two integers z and s in which s is the sum of keys of nodes of the tree and z = 1 if the tree is a BST and z = 0, otherwise
Example
Input
MakeRoot 4
AddRight 5 4
AddLeft 3 4
AddRight 8 5
AddLeft 1 3
AddLeft 7 8
AddLeft 6 7
AddRight 2 1
AddRight 10 8
AddLeft 9 10
*
Output
1 55
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node with the given key
struct TreeNode* createNode(int key)
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if a given binary tree is a BST
bool isBST(struct TreeNode* root, int min, int max)
{
    if (root == NULL) {
        return true;
    }

    if (root->key <= min || root->key >= max) {
        return false;
    }

    return isBST(root->left, min, root->key) && isBST(root->right, root->key, max);
}

// Function to compute the sum of keys of nodes in the tree
int sumKeys(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }

    return root->key + sumKeys(root->left) + sumKeys(root->right);
}

int main()
{
    struct TreeNode* root = NULL;
    int z = 1; // Assume the tree is a BST initially
    int s = 0; // Initialize the sum of keys

    char command[20];
    while (scanf("%s", command) != EOF) {
        if (command[0] == '*') {
            break; // End of input
        }

        if (command[0] == 'M') {
            int u;
            scanf("%d", &u);
            root = createNode(u);
        } else if (command[0] == 'A') {
            int u, v;
            scanf("%d %d", &u, &v);
            struct TreeNode* newNode = createNode(u);
            struct TreeNode* parent = root;
            while (parent) {
                if (v < parent->key) {
                    if (parent->left) {
                        parent = parent->left;
                    } else {
                        parent->left = newNode;
                        break;
                    }
                } else {
                    if (parent->right) {
                        parent = parent->right;
                    } else {
                        parent->right = newNode;
                        break;
                    }
                }
            }
        }
    }

    if (!isBST(root, 1, 100000)) {
        z = 0; // The tree is not a BST
    }

    s = sumKeys(root); // Calculate the sum of keys

    printf("%d %d\n", z, s);

    return 0;
}
