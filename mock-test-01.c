/*
Problem: Xử lý danh sách liên kết đơn
Description
Thông tin các xe đang được gửi trong một bãi xe được lưu trữ bằng danh sách liên kết đơn được khai báo như sau
+ ID: mã thẻ xâu ký tự độ dài 11
+ ngày gửi: dạng xâu ký tự YYYY-MM-DD HH:MM:SS
+ Biển số: dạng xâu ký tự độ dài 10
+ loại xe: 1- xe máy/xe điện, 2- ô tô.

// Khai báo cấu trúc dữ liệu cho mỗi xe
typedef struct Car {
    char ID[12];
    char licensePlate[11];
    char pdate[20];
    int type;
    struct Car* next;
} Car;

1. Hãy hoàn thiện hàm đếm số lượng xe đang có trong bãi
// Hàm để đếm số lượng xe đang có trong bãi
int countCars(Car* head) {

}


2. Hãy hoàn thiện hàm tìm kiếm xe theo biển số

// Hàm để tìm kiếm xe theo biển số
// Trả về NULL nếu không tìm thấy xe
// ngược lại trả về địa chỉ của phần tử chứa biển số
Car* findaCarByLicensePlate(Car* head, char licensePlate[]) {

}

3. Hãy hoàn thiện hàm trả xe (xóa khỏi danh sách)
// Hàm để trả xe dựa trên ID thẻ và xóa khỏi danh sách
// Giải phóng bộ nhớ của xe bị xóa
// hàm trả về 1 nếu xóa thành công và 0 nếu không thành công
int returnCarByID(Car** head, char ID[]) {

}

Tải code tại : https://drive.google.com/file/d/1m7Va4gGgmVBKVrEmgvrZct4fM7jaKe-D/view?usp=sharing
Chú ý.
+ Có thể khai báo biến, kiểu dữ liệu phụ hoặc thư viện ngoài nếu cần.
+ Nếu sử dụng thêm hàm khác, có thể khai báo thêm.
+ Chỉ cần hoàn thiện nốt thân các hàm đã cho, không được thay đổi các tham số của hàm đã có
+ Copy phần code đã được cung cấp để thành chương trình đầy đủ khi submit
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo cấu trúc dữ liệu cho mỗi xe
typedef struct Car {
    char ID[12];
    char licensePlate[11];
    char pdate[20];
    int type;
    struct Car* next;
} Car;

// Hàm để thêm một xe mới vào danh sách liên kết đơn
void addCar(Car** head, char ID[], char licensePlate[], char date[], int type)
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    strcpy(newCar->ID, ID);
    strcpy(newCar->licensePlate, licensePlate);
    strcpy(newCar->pdate, date);
    newCar->type = type;
    newCar->next = NULL;

    if (*head == NULL) {
        *head = newCar;
    } else {
        Car* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newCar;
    }
}

// Hàm để đọc thông tin các xe trong bãi từ input
void readCarList(Car** head)
{
    char ID[12];
    char licensePlate[11];
    char pdate[20], nextLine[100];
    int type;
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
        strcpy(licensePlate, nextLine);

        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        strcpy(pdate, nextLine);

        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%d", &type);
        count++;
        addCar(head, ID, licensePlate, pdate, type);
    }
    printf("Total: %d\n", count);
}

/*
===============================================================
Phần code của sinh viên tại đây!
===============================================================
*/
// Hàm để đếm số lượng xe đang có trong bãi
int countCars(Car* head)
{
    int count = 0;
    Car* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Hàm để tìm kiếm xe theo biển số
// Trả về NULL nếu không tìm thấy xe
// ngược lại trả về địa chỉ của phần tử chứa biển số
Car* findaCarByLicensePlate(Car* head, char licensePlate[])
{
    Car* current = head;
    while (current != NULL) {
        if (strcmp(current->licensePlate, licensePlate) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Không tìm thấy xe
}

// Hàm để trả xe dựa trên ID thẻ và xóa khỏi danh sách
// Giải phóng bộ nhớ của xe bị xóa
// hàm trả về 1 nếu xóa thành công và 0 nếu không thành công
int returnCarByID(Car** head, char ID[])
{
    Car* current = *head;
    Car* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->ID, ID) == 0) {
            if (prev == NULL) {
                // Xóa nút đầu danh sách
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current); // Giải phóng bộ nhớ
            return 1; // Xóa thành công
        }
        prev = current;
        current = current->next;
    }

    return 0; // Không tìm thấy ID thẻ
}

/*
==================================
        Hết phần viết code của sinh viên
==================================
*/

void findCarByLicensePlates(Car* head)
{
    char licensePlate[11];
    Car* aCar = NULL;
    while (1) {
        fgets(licensePlate, sizeof(licensePlate), stdin);
        licensePlate[strcspn(licensePlate, "\r\n")] = 0;
        if (strcmp(licensePlate, "-1") == 0) {
            break;
        }
        aCar = findaCarByLicensePlate(head, licensePlate);
        if (aCar == NULL)
            printf("Plate NOT FOUND\n");
        else
            printf("Found a car parked at %s\n", aCar->pdate);
    }
}

void returnCarByIDs(Car** head)
{
    char ID[12], nextLine[100];
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%s", ID);
        if (strcmp(ID, "-1") == 0) {
            break;
        }
        if (returnCarByID(head, ID))
            printf("DONE Remove\n");
        else
            printf("ID NOT FOUND\n");
    }
}

int main()
{
    Car* carList = NULL;
    char nextCommand[100];
    while (1) {
        fgets(nextCommand, sizeof(nextCommand), stdin);
        nextCommand[strcspn(nextCommand, "\r\n")] = 0;
        if (nextCommand[0] != '?')
            break;
        if (strcmp(&nextCommand[2], "readCarList") == 0)
            readCarList(&carList);
        else if (strcmp(&nextCommand[2], "findCarByLicensePlates") == 0)
            findCarByLicensePlates(carList);
        else if (strcmp(&nextCommand[2], "returnCarByIDs") == 0)
            returnCarByIDs(&carList);
        else if (strcmp(&nextCommand[2], "countCars") == 0)
            printf("Total cars: %d\n", countCars(carList));
    }

    return 0;
}
