#include <stdio.h>

/* Cho hai hoán vị A và B cùng có n phần tử, tại một thời điểm bạn có thể thực
hiện một trong hai loại thao tác sau: Coi dãy A là dãy vòng tròn, ta xoay tròn
dãy A đi một phần tử, ví dụ dãy A={1,2,3} thì sau một thao tác loại này ta sẽ
được dãy A={2,3,1} Nếu hai phần tử đầu tiên của hai dãy A và B bằng nhau thì ta
xóa hai phần tử ở vị trí đầu tiên này đi Hãy tính xem cần ít nhất bao nhiêu thao
tác để xóa hết cả hai dãy đã cho. Input Dòng đầu chứa số n (1≤n≤100) Dòng hai
chứa n số là hoán vị A Dòng ba chứa n số là hoán vị B Output In ra số thao tác
ít nhất cần thực hiện. Example input
3
1 3 2
2 3 1
output
6
*/
int main(void) {
  int n;
  scanf("%d", &n);
  int a[n], b[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (int i = 0; i < n; i++)
    scanf("%d", &b[i]);
  return 0;
}
