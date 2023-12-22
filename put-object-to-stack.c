/*
Problem: Xếp đồ vào ngăn xếp
Description
Viết chương trình C thực hiện nhiệm vụ sau:
a) Khai báo ngăn xếp có chứa các thông tin về dung tích cực đại của một ô trong ngăn xếp và dung tích của phần tử có chứa trong ô đó
typedef struct Node{
int maxCap;
int currCap;
struct Node *next;
} Node;
b) Yêu cầu người dùng nhập vào số lượng các ngăn xếp, số lượng các ô trong ngăn xếp và dung tích cực đại của mỗi ô trong ngăn xếp.
Ví dụ:
5
3
3
2
5
1
4
Giả sử rằng không có ngăn xếp nào có dung tích của từng ô giống hệt nhau.
Ở đây ta có 5 ngăn xếp, mỗi ngăn xếp có thể chứa tối đa ba phần tử, và dung tích của từng ô trong ngăn xếp sẽ lần lượt là 3, 2, 5, 1, 4
c) Yêu cầu người dùng nhập vào số lượng các đồ vật và dung tích của chúng.
ví dụ
7
3
2
3
1
6
5
3
Ở đây người dùng nhập có 7 đồ vật, và dung tích của chúng lần lượt là 3, 2, 3, 1, 6, 5, 3
d) Hãy thực hiện việc xếp các đồ vật vào trong các ngăn xếp, sau đó in ra màn hình số lượng các ngăn xếp còn chỗ trống. Biết rằng người ta ưu tiên xếp phần tử vừa khít với dung tích của ô vào trong ngăn xếp. Nếu dung tích của đồ vật không khít với bất kỳ ô nào, thì ưu tiên xếp đồ vào ô có dung tích bé nhất mà còn lớn hơn dung tích đồ vật.
Nếu không tồn tại ô nào có dung tích lớn hơn dung tích đồ vật thì đồ vật không được cho vào ngăn xếp nào cả.
Ví dụ như ở trên với input là:
5
3
3
2
5
1
4
7
3
2
3
1
6
5
3
Output sẽ là:
4
Giải thích:
ta đặt tên các ngăn xếp A (3), B (2), C(5), D(1), E(4)
đồ vật 3 => xếp vào ngăn xếp A
đồ vật 2 => xếp vào ngăn xếp B
đồ vật 3 => xếp vào ngăn xếp A
đồ vật 1 => xếp vào ngăn xếp D
đồ vật 6 => không xếp vào đâu cả
đồ vật 5 => xếp vào ngăn xếp C
đồ vật 3 => xếp vào ngăn xếp A
Như vậy, ta có ngăn xếp còn trống là B, C, D, E
*/
