/*
Problem: Xử lý cây nhị phân
Description
Thông  tin một nút của cây nhị phân được lưu trữ như sau
typedef struct TNode
{
    char label;
    struct TNode *left, *right;
} TN;

nhãn của nút là các chữ cái hoa từ A-Z.

Hãy hoàn thiện các hàm trong code

1. Đếm và trả về số lượng nút đầy đủ trên cây
// Hàm đếm và trả về số lượng nút đầy đủ trên cây
// nút đầy đủ là các nút có đủ 2 con
int countFullNodes(const TN* root)
{

}

2. đếm và trả về số độ sâu của cây
// hàm tìm độ sâu của cây
// chú ý. cây có 1 nút gốc là lá thì độ sâu là 0
int countLevel(const TN* root)
{
        // CODE THÊM TẠI ĐÂY
}


3. Kiểm tra có phải cây nhị phân tìm kiếm
// Hàm kiểm tra xem cây có phải cây nhị phân tìm kiếm hay không
// nhãn các nút có theo thứ tự A-Z
// Hàm trả về 1 nếu là BST và 0 nếu ngược lại
int isBinarySearchTree(const TN* root)
{
        // CODE THÊM TẠI ĐÂY
}


Tải code tại : https://drive.google.com/file/d/1RkvyavgWmS2npBu4NByk3LhUYsIXp5vx/view?usp=sharing

Chú ý.
+ Có thể khai báo biến, kiểu dữ liệu phụ hoặc thư viện ngoài nếu cần.
+ Nếu sử dụng thêm hàm khác, có thể khai báo thêm.
+ Chỉ cần hoàn thiện nốt thân các hàm đã cho, không được thay đổi các tham số của hàm đã có
+ Copy phần code đã được cung cấp để thành chương trình đầy đủ khi submit
*/

#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct TNode {
    char label;
    struct TNode *left, *right;
} TN;

// tao nut moi
TN* makeNewNode(char label)
{
    TN* newNode = (TN*)malloc(sizeof(TN));
    newNode->left = newNode->right = NULL;
    newNode->label = label;
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
    printf("%c ", root->label);
    inOrderTravel(root->right);
}

void printInOrderTravel(const TN* root)
{
    inOrderTravel(root);
    printf("\n");
}

TN* buildTree()
{
    TN *root, *nNode, *parent;
    int level, i;
    char path[20], label, nextLine[50];
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        if (strstr(nextLine, "-1") != NULL)
            break;
        sscanf(nextLine, "%d %s %c", &level, path, &label);
        if (level == 0) {
            root = makeNewNode(label);
            continue;
        }

        // add decendent nodes
        nNode = makeNewNode(label);
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
// Hàm kiểm tra xem cây có phải cây nhị phân tìm kiếm hay không
// nhãn các nút có theo thứ tự A-Z
// Hàm trả về 1 nếu là BST và 0 nếu ngược lại
int isBinarySearchTree(const TN* root)
{
    if (root == NULL)
        return 1; // Cây rỗng coi như BST
    if (root->label < 'A' || root->label > 'Z')
        return 0; // Kiểm tra nhãn nút

    // Kiểm tra BST cho cả cây con trái và cây con phải
    if (root->left != NULL && root->left->label >= root->label)
        return 0;
    if (root->right != NULL && root->right->label <= root->label)
        return 0;

    return isBinarySearchTree(root->left) && isBinarySearchTree(root->right);
}

void checkIsaBST(const TN* root)
{
    if (isBinarySearchTree(root))
        printf("is a BST\n");
    else
        printf("is not a BST\n");
}

// hàm đếm độ sâu của cây
// chú ý. cây có 1 nút gốc là lá thì độ sâu là 0
int countLevel(const TN* root)
{
    if (root == NULL)
        return -1; // Đặt một giá trị độ sâu không hợp lệ cho trường hợp rỗng
    int leftDepth = countLevel(root->left);
    int rightDepth = countLevel(root->right);
    return 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
}
// Hàm đếm và trả về số lượng nút đầy đủ trên cây
// nút đầy đủ là các nút có đủ 2 con
int countFullNodes(const TN* root)
{
    if (root == NULL)
        return 0;
    if (root->left != NULL && root->right != NULL)
        return 1 + countFullNodes(root->left) + countFullNodes(root->right);
    else
        return countFullNodes(root->left) + countFullNodes(root->right);
}

int main()
{
    TN* root = NULL;
    char nextCommand[50];
    while (1) {
        fgets(nextCommand, sizeof(nextCommand), stdin);
        nextCommand[strcspn(nextCommand, "\r\n")] = 0;
        if (nextCommand[0] != '?')
            break;
        if (strcmp(&nextCommand[2], "buildTree") == 0)
            root = buildTree();
        else if (strcmp(&nextCommand[2], "printInOrderTravel") == 0)
            printInOrderTravel(root);
        else if (strcmp(&nextCommand[2], "checkIsaBST") == 0)
            checkIsaBST(root);
        else if (strcmp(&nextCommand[2], "countLevel") == 0)
            printf("Total levels: %d\n", countLevel(root));
        else if (strcmp(&nextCommand[2], "countFullNodes") == 0)
            printf("Total full nodes: %d\n", countFullNodes(root));
    }

    return 0;
}
