/*
Problem: Inversed binary tree
Description
Đảo ngược cây nhị phân (nút trái thành nút phải và ngược lại).
Dữ liệu nhập vào từ bàn phím có dòng đầu là số nút.
N dòng tiếp theo mỗi dòng chứa nút cha và nút con trái, con phải
(giá trị -1 nếu nút NULL). Cây in ra theo thứ tự InOrder (trái, gốc, phải).
*/
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút trong cây nhị phân
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Hàm tạo một nút mới
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Hàm thêm nút vào cây
Node* insert(Node* root, int parent, int left, int right)
{
    if (root == NULL) {
        root = newNode(parent);
    }

    if (root->data == parent) {
        if (left != -1)
            root->left = newNode(left);
        if (right != -1)
            root->right = newNode(right);
    } else {
        if (root->left)
            insert(root->left, parent, left, right);
        if (root->right)
            insert(root->right, parent, left, right);
    }

    return root;
}

// Hàm đảo ngược cây nhị phân
void invertTree(Node* root)
{
    if (root == NULL)
        return;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);
}

// Hàm in cây theo thứ tự InOrder
void inOrder(Node* root)
{
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    int n, parent, left, right;
    Node* root = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &parent, &left, &right);
        root = insert(root, parent, left, right);
    }

    invertTree(root);
    inOrder(root);

    return 0;
}
