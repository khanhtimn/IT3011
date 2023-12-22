/*
Problem: Binary Tree manipulation & traversal
Description
Mỗi nút của một cây nhị phân T có trường id (định danh của nút, id không trùng lặp nhau). Thực hiện chuỗi các thao tác sau đây trên cây T (ban đầu, T là cây rỗng)

    MakeRoot u: tạo một nút gốc có id bằng u
    AddLeft u v: tạo một nút có id = u và chèn vào vị trí con trái của nút có id bằng v trên T (không thực hiện hành động chèn nếu nút có id bằng u đã tồn tại hoặc nút có id bằng v không tồn tại hoặc nút có id bằng v đã có nút con trái rồi)
    AddRight u v: tạo một nút có id = u và chèn vào vị trí con phải của nút có id bằng v trên T (không thực hiện hành động chèn nếu nút có id bằng u đã tồn tại hoặc nút có id bằng v không tồn tại hoặc nút có id bằng v đã có nút con phải rồi)
    PreOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự trước (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
    InOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự giữa (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
    PostOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự sau (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)


Input

    Mỗi dòng là 1 trong số cách thao tác với định dạng được mô tả ở trên (thao tác MakeRoot chỉ xuất hiện đúng 1 lần và luôn ở ngay dòng đầu tiên). Kết thúc của dữ liệu input là dòng chứa duy nhất ký tự *


Output

    Ghi ra trên 1 dòng kết quả của 1 trong số 3 thao tác InOrder, PreOrder, PostOrder mô tả ở trên


Example
Input
MakeRoot 1
AddLeft 2 1
AddRight 3 1
AddLeft 4 3
AddRight 5 2
PreOrder
AddLeft 6 5
AddRight 7 5
InOrder
*

Output
1 2 5 3 4
2 6 5 7 1 4 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for tree nodes
typedef struct TreeNode {
    int id;
    struct TreeNode *left, *right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int id)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->id = id;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node to the left of a given node
void addLeft(TreeNode** root, int u, int v)
{
    if (*root == NULL)
        return;

    TreeNode* temp = *root;
    if (temp->id == v) {
        if (temp->left == NULL) {
            temp->left = createNode(u);
        }
        return;
    }

    addLeft(&(temp->left), u, v);
    addLeft(&(temp->right), u, v);
}

// Function to insert a node to the right of a given node
void addRight(TreeNode** root, int u, int v)
{
    if (*root == NULL)
        return;

    TreeNode* temp = *root;
    if (temp->id == v) {
        if (temp->right == NULL) {
            temp->right = createNode(u);
        }
        return;
    }

    addRight(&(temp->left), u, v);
    addRight(&(temp->right), u, v);
}

// Function for pre-order traversal
void preOrder(TreeNode* root)
{
    if (root == NULL)
        return;

    printf("%d ", root->id);
    preOrder(root->left);
    preOrder(root->right);
}

// Function for in-order traversal
void inOrder(TreeNode* root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->id);
    inOrder(root->right);
}

// Function for post-order traversal
void postOrder(TreeNode* root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->id);
}

int main()
{
    char command[20];
    int u, v;
    TreeNode* root = NULL;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "*") == 0) {
            break;
        } else if (strcmp(command, "MakeRoot") == 0) {
            scanf("%d", &u);
            root = createNode(u);
        } else if (strcmp(command, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);
            addLeft(&root, u, v);
        } else if (strcmp(command, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            addRight(&root, u, v);
        } else if (strcmp(command, "PreOrder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(command, "InOrder") == 0) {
            inOrder(root);
            printf("\n");
        } else if (strcmp(command, "PostOrder") == 0) {
            postOrder(root);
            printf("\n");
        }
    }

    return 0;
}
