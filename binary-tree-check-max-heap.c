/*
Problem: Binary tree - check max heap - full children nodes
Description
Each node of a binary tree has id which is an integer representing the identifier of the node.
Perform a sequence of operations of 3 types belows for constructing the tree T (T is initialized by an empty tree)

    make-root u: create the root having id = u (u is an integer, 1 <= u <= 100000)
    add-left  u  v (u,v are integers, 1 <= u,v <= 100000): create a node having id = u and insert this node as a left-child of the node having id = v in T (do not perform the operation if the node having id = v does not exist or the node having id = u exists or the node having id = v has already a left-child)
    add-right u  v (u,v are integers, 1 <= u,v <= 100000): create a node having id = u and insert this node as a right-child of the node having id = v in T (do not perform the operation if the node having id = v does not exist or the node having id = u exists or the node having id = v has already a right-child)

A sub-tree (by convention, T is a sub-tree of itself) is call a max-heap if the id of each node is greater than the ids of its chlidren.
Perform a sequence of equeries of 2 types belows:

    is-max-heap  u (u is an integer, 1 <= u <= 100000): return 1 if the sub-tree (of T) rooted at u is a max-heap, and return 0, otherwise (if the node having id = u does not exist, then return 1)
    count-nodes-having-2-children  u (u is an integer, 1 <= u <= 100000): return the number of nodes having both left-child and right-child in the sub-tree (of T) rooted at u.


Input
Consists of two block of information:

    The first block is a sequence of lines, each line is an operation of 3 type above (note: the operation make-root appears exactly once and at the beginning of the block). The first block is terminated by a line containing the character *
    The second block is a sequence of lines, each line is a query. The second block is terminated by a line containing ***

Output

    Write on each line, the result of the corresponding query of the second block described above

Example
Input
make-root 9
add-left 5 9
add-right 7 9
add-left 1 5
add-right 4 5
add-left 2 7
add-right 3 7
*
is-max-heap 5
count-nodes-having-2-children 9
***
Output
1
3
*/
#include <stdio.h>
#include <stdlib.h>

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

int is_max_heap(Node* root)
{
    if (root == NULL)
        return 1;
    if (root->left && root->id < root->left->id)
        return 0;
    if (root->right && root->id < root->right->id)
        return 0;
    return is_max_heap(root->left) && is_max_heap(root->right);
}

int count_nodes_with_2_children(Node* root)
{
    if (root == NULL)
        return 0;
    int count = (root->left && root->right) ? 1 : 0;
    return count + count_nodes_with_2_children(root->left) + count_nodes_with_2_children(root->right);
}

int main()
{
    Node* root = NULL;
    char operation[20];
    int u, v;
    while (scanf("%s", operation) != EOF) {
        if (operation[0] == '*')
            break;
        if (strcmp(operation, "make-root") == 0) {
            scanf("%d", &u);
            root = create_node(u);
        } else if (strcmp(operation, "add-left") == 0) {
            scanf("%d %d", &u, &v);
            Node* parent = find_node(root, v);
            if (parent && find_node(root, u) == NULL && parent->left == NULL)
                add_child(parent, create_node(u), 'L');
        } else if (strcmp(operation, "add-right") == 0) {
            scanf("%d %d", &u, &v);
            Node* parent = find_node(root, v);
            if (parent && find_node(root, u) == NULL && parent->right == NULL)
                add_child(parent, create_node(u), 'R');
        }
    }

    while (scanf("%s", operation) != EOF) {
        if (operation[0] == '*' && operation[1] == '*')
            break;
        scanf("%d", &u);
        Node* node = find_node(root, u);
        if (strcmp(operation, "is-max-heap") == 0) {
            printf("%d\n", node ? is_max_heap(node) : 1);
        } else if (strcmp(operation, "count-nodes-having-2-children") == 0) {
            printf("%d\n", node ? count_nodes_with_2_children(node) : 0);
        }
    }

    // Free memory and perform cleanup here if necessary

    return 0;
}
