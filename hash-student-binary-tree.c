/*
Problem: Quản lý hồ sơ hash function
Description
Một hồ sơ sinh viên có 2 thông tin chính như sau
•Name
•Email
Hãy viết một chương trình chạy trên chế độ interactive với các lệnh sau:
•Load<filename>: Nạp dữ liệu từ1 file văn bản
•Find<student_name>: Trả về hồ sơ của sinh viên có tên được nhập vào
•Insert <student_name> <email>: Chèn một hồ sơ sinh viên mới vào cuối danh sách
•Remove <student_name>: loại bỏ hồ sơ sinh viên
•Store <filename>: Lưu trữ danh sách hồ sơ lênfile văn bản
•Quit: thoát khỏi chương trình
Yêu cầu: sử dụng bảng băm kết hợp cây nhị phân tìm kiếm, xử lý xung đột theo cơ chế nhóm chuỗi (chaining)
Input
Load
2
chung chung@hust.edu.vn
xu xu@gmail.com
Find
chung
Quit
Output
53 chung@hust.edu.vn
Bye
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Student {
    char name[50];
    char email[100];
} Student;

typedef struct TreeNode {
    Student data;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct HashTable {
    TreeNode* table[TABLE_SIZE];
} HashTable;

// Prototypes
int hash(char* str);
TreeNode* createNode(Student s);
void insertHashTable(HashTable* hashTable, Student s);
TreeNode* insertTreeNode(TreeNode* root, Student s);
TreeNode* findTreeNode(TreeNode* root, char* name);
void removeTreeNode(TreeNode** root, char* name);
void load(HashTable* hashTable);
void store(TreeNode* root, FILE* file);
void quit(HashTable* hashTable);

int main()
{
    HashTable hashTable = { 0 };
    char command[50];

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "Load") == 0) {
            load(&hashTable);
        } else if (strcmp(command, "Find") == 0) {
            char name[50];
            scanf("%s", name);
            TreeNode* node = findTreeNode(hashTable.table[hash(name)], name);
            if (node) {
                printf("%d %s\n", hash(name), node->data.email);
            } else {
                printf("Not found\n");
            }
        } else if (strcmp(command, "Quit") == 0) {
            printf("Bye\n");
            quit(&hashTable);
            break;
        }
    }

    return 0;
}

int hash(char* str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c

    return hash % TABLE_SIZE;
}

TreeNode* createNode(Student s)
{
    TreeNode* newNode = malloc(sizeof(TreeNode));
    if (newNode) {
        newNode->data = s;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

void insertHashTable(HashTable* hashTable, Student s)
{
    int index = hash(s.name);
    TreeNode* root = hashTable->table[index];
    hashTable->table[index] = insertTreeNode(root, s);
}

TreeNode* insertTreeNode(TreeNode* root, Student s)
{
    if (root == NULL)
        return createNode(s);

    if (strcmp(s.name, root->data.name) < 0)
        root->left = insertTreeNode(root->left, s);
    else if (strcmp(s.name, root->data.name) > 0)
        root->right = insertTreeNode(root->right, s);

    return root;
}

TreeNode* findTreeNode(TreeNode* root, char* name)
{
    if (root == NULL)
        return NULL;

    if (strcmp(name, root->data.name) == 0)
        return root;
    else if (strcmp(name, root->data.name) < 0)
        return findTreeNode(root->left, name);
    else
        return findTreeNode(root->right, name);
}

// Hàm hỗ trợ để tìm nút thay thế
TreeNode* minValueNode(TreeNode* node)
{
    TreeNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Hàm xóa nút
void removeTreeNode(TreeNode** root, char* name)
{
    if (*root == NULL)
        return;

    if (strcmp(name, (*root)->data.name) < 0)
        removeTreeNode(&(*root)->left, name);
    else if (strcmp(name, (*root)->data.name) > 0)
        removeTreeNode(&(*root)->right, name);
    else {
        // Nút có một hoặc không có con
        if ((*root)->left == NULL) {
            TreeNode* temp = (*root)->right;
            free(*root);
            *root = temp;
        } else if ((*root)->right == NULL) {
            TreeNode* temp = (*root)->left;
            free(*root);
            *root = temp;
        } else {
            // Nút có hai con: lấy nút nhỏ nhất từ cây con phải
            TreeNode* temp = minValueNode((*root)->right);
            (*root)->data = temp->data;
            removeTreeNode(&(*root)->right, temp->data.name);
        }
    }
}

void load(HashTable* hashTable)
{
    int numEntries;
    scanf("%d", &numEntries);
    Student s;

    for (int i = 0; i < numEntries; i++) {
        scanf("%s %s", s.name, s.email);
        insertHashTable(hashTable, s);
    }
}

void store(TreeNode* root, FILE* file)
{
    if (root == NULL)
        return;
    store(root->left, file);
    fprintf(file, "%s %s\n", root->data.name, root->data.email);
    store(root->right, file);
}

void freeTree(TreeNode* root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void quit(HashTable* hashTable)
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        freeTree(hashTable->table[i]);
    }
}
