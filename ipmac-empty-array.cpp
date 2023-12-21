#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int b[n];
  int m = n;
  int count = 0;
  int i = 0, j = 0;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  while (j != n) {
    count++;
    if (a[i] != b[j])
      a[m++] = a[i];
    else
      j++;
    i++;
  }
  cout << count << endl;
  return 0;
}
