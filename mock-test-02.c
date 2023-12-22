/*
Problem: xử lý giỏ hàng dùng danh sách liên kết đơn
Description
Chú ý.
+ Có thể khai báo biến, kiểu dữ liệu phụ hoặc thư viện ngoài nếu cần.
+ Nếu sử dụng thêm hàm khác, có thể khai báo thêm.
+ Chỉ cần hoàn thiện nốt thân các hàm đã cho, không thay đổi các tham số của hàm đã có.
+ Cần giữ nguyên tên hàm đúng với mô tả (tên hàm có phân biệt HOA và thường).
+ Để các hàm tại đúng vị trí trong phần file code đã được chỉ rõ trong comment
+ Làm được hàm nào tính điểm hàm đó
+ Hàm nào không làm được vẫn cần copy thông tin đủ như phần mô tả ở dưới vào code trước khi submit code trong hệ thống openERP nếu không sẽ có LỖI biên dịch! (có thể bỏ qua các comment)
+ Chú ý giá trị trả về mặc định của hàm với một số hàm
======================
name: xử lý giỏ hàng dùng danh sách liên kết đơn
Để lưu trữ thông tin sản phẩm trong giỏ hàng khi mua hàng online ta dùng một danh sách liên kết đơn với cấu trúc một node được khai báo như sau
+ ID: mã sản phẩm
+ số lượng: kiểu số nguyên
+ thời điểm thêm: dạng xâu ký tự YYYY-MM-DD HH:MM:SS
+ giá bán 1 sản phẩm: kiểu số thực

// Khai báo cấu trúc dữ liệu cho sản phẩm
 typedef struct Item {
  char ID[12];
  int quantity;
  char insertDate[21];
  double price;
  struct Item* next;
} Item;


 Hãy hoàn thiện các hàm sau
1. Tính tổng số lượng hàng đang có trong giỏ và tổng tiền
// Hàm tính tổng tiền sản phẩm trong giỏ hàng
double checkCartTotalPrice(Item* head) {
  // SINH VIÊN CODE TIẾP VÀO ĐÂY
  return 0.0;
}

2. Tìm kiếm một sản phẩm có trong giỏ hàng theo ID sản phẩm
// Hàm để tìm kiếm sản phẩm theo mã ID
// Trả về NULL nếu không tìm thấy
// ngược lại trả về địa chỉ của phần tử chứa ID
Item* findanItemByID(Item* head, char ID[]) {
  // SINH VIÊN CODE TIẾP VÀO ĐÂY
  return NULL;
}


3. Giảm số lượng 1 mã sản phẩm, nếu số lượng là 0 thì xóa khỏi giỏ hàng
// Hàm giảm số lượng 1 mã sản phẩm
// Nếu số lượng sản phẩm trong giỏ hàng ít hơn hoặc bằng số lượng // cần giảm thì xóa sản phẩm đó khỏi giỏ hàng
// hàm trả về 1 nếu điều chỉnh thành công và 0 nếu không thành công // (ID không tìm thấy)
int reduceItemQuantityByID(Item** head, char ID[],
  int reduceQuantity) {
  // SINH VIÊN CODE TIẾP VÀO ĐÂY
  return 0;
}

 4. Thêm 1 sản phẩm vào giỏ hàng theo ID, nếu đã có thì tăng số lượng, chưa có thì thêm vào cuối danh sách trong giỏ.
// Hàm để thêm một sản phẩm vào giỏ hàng, nếu đã có thì tăng số
// lượng lên, nếu chưa có thì thêm vào cuối danh sách
// các thông tin được truyền như tham số hàm, ý nghĩa các trường
// giống như tên trường
void addNewItem(Item** head, char ID[], int quantity,
  char insertDate[],  double price) {

 }
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

// Khai báo cấu trúc dữ liệu cho sản phẩm

typedef struct Item {

    char ID[12];

    int quantity;

    char insertDate[21];

    double price;

    struct Item* next;

} Item;

// Hàm để thêm một sản phẩm vào giỏ hàng

void addItem(Item** head, char ID[], int quantity, char insertDate[], double price)
{

    Item* newItem = (Item*)malloc(sizeof(Item));

    strcpy(newItem->ID, ID);

    newItem->quantity = quantity;

    strcpy(newItem->insertDate, insertDate);

    newItem->price = price;

    newItem->next = NULL;

    if (*head == NULL) {

        *head = newItem;

    }

    else {

        Item* temp = *head;

        while (temp->next != NULL) {

            temp = temp->next;
        }

        temp->next = newItem;
    }
}

// Hàm để đọc thông tin các sản phẩm input

void readItemList(Item** head)
{

    char ID[12];

    int quantity;

    char insertDate[21];

    char nextLine[100];

    double price;

    int count = 0;

    while (1) {

        fgets(nextLine, sizeof(nextLine), stdin);

        nextLine[strcspn(nextLine, "\r\n")] = 0;

        sscanf(nextLine, "%s", ID);

        if (strlen(ID) == 0)
            continue;

        if (strcmp(ID, "-1") == 0) {

            break;
        }

        fgets(nextLine, sizeof(nextLine), stdin);

        nextLine[strcspn(nextLine, "\r\n")] = 0;

        sscanf(nextLine, "%d", &quantity);

        fgets(nextLine, sizeof(nextLine), stdin);

        nextLine[strcspn(nextLine, "\r\n")] = 0;

        strcpy(insertDate, nextLine);

        fgets(nextLine, sizeof(nextLine), stdin);

        nextLine[strcspn(nextLine, "\r\n")] = 0;

        sscanf(nextLine, "%lf", &price);

        count++;

        addItem(head, ID, quantity, insertDate, price);
    }

    printf("Total: %d\n", count);
}

/////////////////////////////////////////////////////////////////////////////////

// PHẦN CODE LÀM CỦA SINH VIÊN

//////////////////////////////////////////////////

// Hàm tính tổng tiền sản phẩm trong giỏ hàng

double checkCartTotalPrice(Item* head)
{

    double total = 0.0;

    Item* current = head;

    while (current != NULL) {

        total += (current->price * current->quantity);

        current = current->next;
    }

    return total;
}

// Hàm để tìm kiếm sản phẩm theo mã ID

// Trả về NULL nếu không tìm thấy

// ngược lại trả về địa chỉ của phần tử chứa ID

Item* findanItemByID(Item* head, char ID[])
{

    Item* current = head;

    while (current != NULL) {

        if (strcmp(current->ID, ID) == 0) {

            return current;
        }

        current = current->next;
    }

    return NULL;
}

// Hàm giảm số lượng 1 mã sản phẩm

// Nếu số lượng sản phẩm trong giỏ hàng ít hơn hoặc bằng số lượng // cần giảm thì xóa sản phẩm đó khỏi giỏ hàng

// hàm trả về 1 nếu điều chỉnh thành công và 0 nếu không thành công // (ID không tìm thấy)

int reduceItemQuantityByID(Item** head, char ID[], int reduceQuantity)
{

    Item* current = *head;

    Item* prev = NULL;

    while (current != NULL) {

        if (strcmp(current->ID, ID) == 0) {

            if (current->quantity <= reduceQuantity) {

                // Xóa sản phẩm khỏi giỏ hàng

                if (prev == NULL) {

                    *head = current->next;

                } else {

                    prev->next = current->next;
                }

                free(current);

                return 1; // Đã xóa thành công

            } else {

                // Giảm số lượng sản phẩm

                current->quantity -= reduceQuantity;

                return 1; // Đã giảm số lượng thành công
            }
        }

        prev = current;

        current = current->next;
    }

    return 0; // ID không tìm thấy trong giỏ hàng
}

// Hàm để thêm một sản phẩm vào giỏ hàng, nếu đã có thì tăng số

// lượng lên, nếu chưa có thì thêm vào cuối danh sách

// các thông tin được truyền như tham số hàm, ý nghĩa các trường

// giống như tên trường

void addNewItem(Item** head, char ID[], int quantity, char insertDate[], double price)
{

    Item* newItem = (Item*)malloc(sizeof(Item));

    strcpy(newItem->ID, ID);

    newItem->quantity = quantity;

    strcpy(newItem->insertDate, insertDate);

    newItem->price = price;

    newItem->next = NULL;

    if (*head == NULL) {

        *head = newItem;

    } else {

        Item* current = *head;

        while (current->next != NULL) {

            current = current->next;
        }

        current->next = newItem;
    }
}

///////////////////////////////////////////////////

// HẾT PHẦN LÀM CỦA SINH VIÊN

////////////////////////////////////////////////////////////////////////////////

void findItemsByID(Item* head)

{

    char ID[11], nextLine[100];
    ;

    Item* anItem = NULL;

    while (1) {

        fgets(nextLine, sizeof(nextLine), stdin);

        nextLine[strcspn(nextLine, "\r\n")] = 0;

        sscanf(nextLine, "%s", ID);

        if (strcmp(ID, "-1") == 0) {

            break;
        }

        anItem = findanItemByID(head, ID);

        if (anItem == NULL)
            printf("Item NOT FOUND\n");

        else
            printf("Item's already added at %s\n", anItem->insertDate);
    }
}

void reduceItemQuantityByIDs(Item** head)

{

    char ID[12], nextLine[100];

    int reduceQuantity;

    while (1) {

        fgets(nextLine, sizeof(nextLine), stdin);

        nextLine[strcspn(nextLine, "\r\n")] = 0;

        sscanf(nextLine, "%s %d", ID, &reduceQuantity);

        if (strcmp(ID, "-1") == 0) {

            break;
        }

        if (reduceItemQuantityByID(head, ID, reduceQuantity))

            printf("DONE Remove\n");

        else

            printf("ID NOT FOUND\n");
    }
}

// Hàm để đọc thông tin các sản phẩm input

void addNewItems(Item** head)
{

    char ID[12];

    int quantity;

    char insertDate[21];

    char nextLine[100];

    double price;

    while (1) {

        fgets(nextLine, sizeof(nextLine), stdin);

        nextLine[strcspn(nextLine, "\r\n")] = 0;

        sscanf(nextLine, "%s", ID);

        if (strlen(ID) == 0)
            continue;

        if (strcmp(ID, "-1") == 0) {

            break;
        }

        fgets(nextLine, sizeof(nextLine), stdin);

        nextLine[strcspn(nextLine, "\r\n")] = 0;

        sscanf(nextLine, "%d", &quantity);

        fgets(nextLine, sizeof(nextLine), stdin);

        nextLine[strcspn(nextLine, "\r\n")] = 0;

        strcpy(insertDate, nextLine);

        fgets(nextLine, sizeof(nextLine), stdin);

        nextLine[strcspn(nextLine, "\r\n")] = 0;

        sscanf(nextLine, "%lf", &price);

        addNewItem(head, ID, quantity, insertDate, price);
    }
}

// Hàm để test các hàm đã định nghĩa ở trên

int main()
{

    Item* cartList = NULL;

    char nextCommand[100];

    while (1)

    {

        fgets(nextCommand, sizeof(nextCommand), stdin);

        nextCommand[strcspn(nextCommand, "\r\n")] = 0;

        if (nextCommand[0] != '?')
            break;

        if (strcmp(&nextCommand[2], "readCart") == 0)

            readItemList(&cartList);

        else if (strcmp(&nextCommand[2], "findItemsByID") == 0)

            findItemsByID(cartList);

        else if (strcmp(&nextCommand[2], "reduceItemQuantityByIDs") == 0)

            reduceItemQuantityByIDs(&cartList);

        else if (strcmp(&nextCommand[2], "addNewItems") == 0)

            addNewItems(&cartList);

        else if (strcmp(&nextCommand[2], "checkCartTotalPrice") == 0)

            printf("Total price: %.2lf\n", checkCartTotalPrice(cartList));
    }

    return 0;
}
