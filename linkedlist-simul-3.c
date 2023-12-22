/*
Problem: DOANPHONGTUNG_Thao_Tac_List
Description
Cho cấu trúc có dạng:
typedef struct Node {
int value;
struct Node* next;
} Node;
Hãy xây dựng danh sách liên kết đơn chứa một dãy số nguyên nhập vào từ bàn phím. Tiếp tục thực hiện một dãy các thao tác như:

    addlast  k: thêm phần tử có value bằng k vào cuối danh sách (nếu k chưa tồn tại)
    addfirst  k: thêm phần tử có value bằng k vào đầu danh sách (nếu k chưa tồn tại)
    addafter  u  v: thêm phần tử có value bằng u vào sau phần tử có value bằng v trên danh sách (nếu v đã tồn tại trên danh sách)
    addbefore  u  v: thêm phần tử có value bằng  u vào trước phần tử có value bằng v trên danh sách (nếu v đã tồn tại trên danh sách)
    remove k: loại bỏ hết các phần tử có key bằng k khỏi danh sách
    reverse: đảo ngược thứ tự các phần tử của danh sách (không được cấp phát mới các phần tử, chỉ được thay đổi mối nối liên kết)

Ví dụ:
Input:
5 4 3 2 1
addlast 3
addlast 10
addfirst 1
addafter 10 4
remove 1
#
Output:
5 4 3 2 10
*/
