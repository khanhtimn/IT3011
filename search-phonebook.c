/*
Problem: CBASIC_Search_Phonebook_LL_Search
Description
Cho cấu trúc một bản tin trong danh bạ điện thoại như sau:
typedef struct {
  char name[20];
  char tel[20];
  char email[32];
} phoneAddr_t;
Cài đặt hàm tìm kiếm một người theo tên trong danh sách liên kết (DSLK).
int main() {
   char key[20];
    nhập các bản ghi người từ bàn phím: nếu tên bằng "#" thì kết thúc việc nhập. Chú ý, các phần tử được thêm vào đầu DSLK.
   nhập khóa là tên người cần tìm thông tin, trả về thông tin người tìm được, trả về "Not found" nếu không tìm thấy
   thực hiện các thao tác cần thiết trước khi kết thúc chương trình
return 0;
}
Ví dụ 1:
INPUT:
A 12345678 a@gmail.com
B 12345678 b@gmail.com
C 12345678 c@gmail.com
#
C
2 C 12345678 c@gmail.com
Ví dụ 2:
INPUT:
A 12345678 a@gmail.com
B 12345678 b@gmail.com
C 12345678 c@gmail.com
#
D
Not found
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char tel[20];
    char email[32];
} phoneAddr_t;

typedef struct Node {
    phoneAddr_t data;
    struct Node* next;
} Node;

Node* createNode(phoneAddr_t data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(Node** head, phoneAddr_t data)
{
    Node* newNode = createNode(data);
    if (newNode != NULL) {
        newNode->next = *head;
        *head = newNode;
    }
}

Node* searchByName(Node* head, char* name)
{
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main()
{
    Node* head = NULL;
    phoneAddr_t temp;
    char key[20];

    // Nhập dữ liệu
    while (1) {
        scanf("%s", temp.name);
        if (strcmp(temp.name, "#") == 0)
            break;
        scanf("%s %s", temp.tel, temp.email);
        insertAtHead(&head, temp);
    }

    // Tìm kiếm
    scanf("%s", key);
    Node* found = searchByName(head, key);
    if (found != NULL) {
        printf("%s %s %s\n", found->data.name, found->data.tel, found->data.email);
    } else {
        printf("Not found\n");
    }

    // Giải phóng bộ nhớ và kết thúc chương trình
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
