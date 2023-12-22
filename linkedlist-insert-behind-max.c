/*
Problem: DOANPHONGTUNG_Chen_Sau_Max
Description
Cho cấu trúc có dạng:
typedef struct Node {
int value;
struct Node* next;
} Node;
Hãy xây dựng danh sách liên kết đơn chứa một dãy số nguyên nhập vào từ bàn phím. Tiếp tục nhận một giá trị từ bàn phím và chèn giá trị đó vào sau node có giá trị lớn nhất trong dãy. Hiển thị ra màn hình danh sách sau khi chèn.
Mô tả đầu vào: gồm hai dòng, dòng thứ nhất gồm dãy số nguyên ngăn cách nhau bởi một khoảng trắng, dòng thứ hai chứa giá trị cần chèn.
Ví dụ:
Input:
1 5 6 9 3 2
5
Output:
1 5 6 9 5 3 2
Lưu ý: nếu dãy số cho ở dòng thứ nhất là rỗng, mặc định danh sách có một node với giá trị bằng 0.
*/
