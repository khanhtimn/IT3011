#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode {
    int key;
    struct TNode *left, *right;
} TN;

// tao nut moi
TN* makeNewNode(int key)
{
    TN* newNode = (TN*)malloc(sizeof(TN));
    newNode->left = newNode->right = NULL;
    newNode->key = key;
    return newNode;
}
// then nut moi vao cay
// root la nut cha va nNode la nut moi them
// tham so rtype = L --> them vao con trai va R thi them vao con phai
void addNodeToTree(TN* root, TN* nNode, char rtype)
{
    if (rtype == 'L')
        root->left = nNode;
    else
        root->right = nNode;
}

// duyet cay theo thu tu giua
void inOrderTravel(const TN* root)
{
    if (NULL == root)
        return;
    inOrderTravel(root->left);
    printf("%d ", root->key);
    inOrderTravel(root->right);
}

void printInOrderTravel(const TN* root)
{
    inOrderTravel(root);
    printf("\n");
}

TN* buildTree()
{
    TN *root = NULL, *nNode, *parent;
    int level, i, key;
    char path[20], nextLine[100];
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        if (strstr(nextLine, "-1") != NULL)
            break;
        sscanf(nextLine, "%d %s %d", &level, path, &key);
        if (level == 0) {
            root = makeNewNode(key);
            continue;
        }

        // add decendent nodes
        nNode = makeNewNode(key);
        parent = root;
        for (i = 0; i < strlen(path) - 1; i++)
            if (path[i] == 'R')
                parent = parent->right;
            else
                parent = parent->left;
        addNodeToTree(parent, nNode, path[i]);
    }
    return root;
}
/*
==========================================
Phần viết code của sinh viên
===========================================
*/

int hasDuplicateItemHelper(const TN* node, int values[])
{
    if (node == NULL)
        return 0;

    if (values[node->key] == 1)
        return 1;

    values[node->key] = 1;

    return hasDuplicateItemHelper(node->left, values) || hasDuplicateItemHelper(node->right, values);
}

// Tìm lá nhỏ nhất trên cây
TN* smallestLeaf(TN* root)
{
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL)
        return root;

    TN* leftSmallest = smallestLeaf(root->left);
    TN* rightSmallest = smallestLeaf(root->right);

    if (leftSmallest == NULL)
        return rightSmallest;
    if (rightSmallest == NULL)
        return leftSmallest;

    return leftSmallest->key < rightSmallest->key ? leftSmallest : rightSmallest;
}

// Lưu trữ giá trị cây theo thứ tự trung tố vào mảng
void storeInOrder(const TN* node, int arr[], int* n)
{
    if (node == NULL)
        return;
    storeInOrder(node->left, arr, n);
    arr[(*n)++] = node->key;
    storeInOrder(node->right, arr, n);
}

// Kiểm tra xem cây có phần tử trùng lặp không
int hasDuplicateItem(const TN* root)
{
    // Sử dụng một mảng để lưu trữ giá trị đã xuất hiện
    int values[1000] = { 0 }; // Chú ý: Điều này giới hạn độ sâu của cây
    return hasDuplicateItemHelper(root, values);
}

// Đếm số lượng nút đặc biệt trên cây
int countSpecialNodes(const TN* root, int k)
{
    if (root == NULL)
        return 0;

    int count = 0;

    // Nếu giá trị của nút lớn hơn hoặc bằng k, tăng biến đếm lên 1
    if (root->key >= k)
        count++;

    // Đệ quy vào cây con trái và cây con phải để đếm các nút đặc biệt
    count += countSpecialNodes(root->left, k);
    count += countSpecialNodes(root->right, k);

    return count;
}

// Hàm so sánh để sử dụng với qsort
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

// Chuyển đổi mảng giá trị đã sắp xếp thành BST
void convertToBST(TN* node, int arr[], int* n)
{
    if (node == NULL)
        return;
    convertToBST(node->left, arr, n);
    node->key = arr[(*n)++];
    convertToBST(node->right, arr, n);
}

// Chuyển đổi cây thành một cây nhị phân tìm kiếm
void convertToBinarySearchTree(TN* root)
{
    int* arr = (int*)malloc(sizeof(int) * 1000); // Điều này giới hạn số lượng nút của cây
    int n = 0;
    storeInOrder(root, arr, &n);
    qsort(arr, n, sizeof(int), compare); // Sắp xếp mảng giá trị cây

    n = 0;
    convertToBST(root, arr, &n);
    free(arr);
}

/*
=====================================
Hết phần viết code
===============================
*/

void checkDuplicateItemonTree(TN* root)
{
    if (hasDuplicateItem(root))
        printf("Tree has some duplicate items!\n");
    else
        printf("There is no dulplicate item on the tree!\n");
}
void countListSpecialNodes(const TN* root)
{
    char nextLine[100];
    int k;
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        if (strstr(nextLine, "-1") != NULL)
            break;
        sscanf(nextLine, "%d", &k);
        printf("Total special nodes >=%d: %d\n", k, countSpecialNodes(root, k));
    }
}

void printSmallestLeaf(TN* root)
{
    TN* smLeaf = smallestLeaf(root);
    if (smLeaf != NULL)
        printf("Smallest Leaf : %d\n", smLeaf->key);
    else
        printf("There is no leaf on the tree!\n");
}
int main()
{
    TN* root = NULL;
    char nextCommand[100];
    while (1) {
        fgets(nextCommand, sizeof(nextCommand), stdin);
        nextCommand[strcspn(nextCommand, "\r\n")] = 0;
        if (nextCommand[0] != '?')
            break;
        if (strcmp(&nextCommand[2], "buildTree") == 0)
            root = buildTree();
        else if (strcmp(&nextCommand[2], "printInOrderTravel") == 0)
            printInOrderTravel(root);
        else if (strcmp(&nextCommand[2], "countSpecialNodes") == 0)
            countListSpecialNodes(root);
        else if (strcmp(&nextCommand[2], "printSmallestLeaf") == 0)
            printSmallestLeaf(root);
        else if (strcmp(&nextCommand[2], "hasDuplicateItem") == 0)
            checkDuplicateItemonTree(root);
        else if (strcmp(&nextCommand[2], "convertToBinarySearchTree") == 0)
            convertToBinarySearchTree(root);
    }

    return 0;
}
