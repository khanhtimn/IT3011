/*
Problem: Check balanced binary tree and compute the height
Description
Each node of a binary tree has a field id which is the identifier of the node. Build a binary tree and check if the tree is a balanced tree, compute the height of the given tree (the number of nodes of the tree can be upto 50000)
Input

    Line 1 contains MakeRoot u: make the root of the tree having id = u
    Each subsequent line contains: AddLeft or AddRightcommands with the format
    AddLeft u v: create a node having id = u, add this node as a left-child of the node with id = v (if not exists)
    AddRight u v: create a node having id = u, add this node as a right-child of the node with id = v (if not exists)
    The last line contains * which marks the end of the input

Output

    Write two integers z and h (separated by a SPACE character) in which h is the height (the number of nodes of the longest path from the root to a leaf) and z = 1 if the tree is balanced and z = 0, otherwise


Example
Input
MakeRoot 1
AddLeft 2 1
AddRight 3 1
AddLeft 9 2
AddRight 4 2
AddLeft 6 3
AddRight 5 3
AddLeft 7 4
AddRight 8 4
*
Output
1 4
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node *left, *right;
} Node;

Node* create_node(int id)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->id = id;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void add_child(Node* parent, Node* child, char child_type)
{
    if (child_type == 'L')
        parent->left = child;
    else
        parent->right = child;
}

Node* find_node(Node* root, int id)
{
    if (root == NULL || root->id == id)
        return root;
    Node* found = find_node(root->left, id);
    if (found == NULL)
        found = find_node(root->right, id);
    return found;
}

int check_balance_and_height(Node* node, int* balanced)
{
    if (node == NULL)
        return 0;

    int left_height = check_balance_and_height(node->left, balanced);
    int right_height = check_balance_and_height(node->right, balanced);

    if (abs(left_height - right_height) > 1)
        *balanced = 0;

    return 1 + (left_height > right_height ? left_height : right_height);
}

int main()
{
    Node* root = NULL;
    char operation[10];
    int u, v;
    while (scanf("%s", operation) != EOF && operation[0] != '*') {
        scanf("%d", &u);
        if (strcmp(operation, "MakeRoot") == 0) {
            root = create_node(u);
        } else {
            scanf("%d", &v);
            Node* parent = find_node(root, v);
            if (parent) {
                Node* child = create_node(u);
                add_child(parent, child, operation[3] == 'L' ? 'L' : 'R');
            }
        }
    }

    int balanced = 1;
    int height = check_balance_and_height(root, &balanced);
    printf("%d %d\n", balanced, height);

    // Free memory and perform cleanup here if necessary

    return 0;
}
