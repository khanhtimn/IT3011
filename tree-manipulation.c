/*
Problem: DOANPHONGTUNG_Thao_Tac_Cay
Description
Cho cấu trúc như sau:
typedef struct Node {
char id;
struct Node* leftMostChild;
struct Node* rightSibling;
} Node;
Hãy xây dựng cấu trúc dữ liệu cây và thực hiện một số thao tác sau:

    MakeRoot u: tạo ra nút gốc u của cây
    AddChild u v: tạo mới 1 nút v và chèn vào cuối danh sách nút con của nút u (nếu nút có id bằng u không tồn tại hoặc nút có id bằng v đã tồn tại thì không chèn thêm mới)
    PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
    InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
    PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau
    Height u: in ra chiều cao của nút u
    CountTree u: in ra số nút của cây có gốc ở u
    CountChild u: in ra số nút con của nút u
    CountLeaves u: in ra số nút lá của cây có gốc ở u

Dữ liệu vào: bao gồm các dòng, mỗi dòng là 1 trong số các thao tác được mô tả ở trên, dòng cuối dùng là # (đánh dấu sự kết thúc của dữ liệu).
Kết quả: ghi ra trên mỗi dòng tương ứng với dữ liệu đọc được.
Ví dụ
Dữ liệu:
MakeRoot a
AddChild a b
AddChild a c
AddChild a d
AddChild b e
AddChild b f
PreOrder
AddChild c g
AddChild d h
AddChild f i
AddChild f j
AddChild j k
PostOrder
Height h
CountTree b
CountChild c
CountLeaves f
#
Kết quả:
a b e f c d
e i k j f b g c h d a
1
6
1
2
*/
