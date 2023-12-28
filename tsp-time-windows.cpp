/*
Problem: TSP with Time Windows
Description
Một nhân viên giao hàng lấy hàng ở kho (điểm 0) và cần đi giao hàng cho N khách hàng 1,2,…, N. Khách hàng i nằm ở điểm i và có yêu cầu giao hàng trong khoảng thời gian từ e(i) đến l(i) và giao hàng hết d(i)  đơn vị thời gian (s). Biết rằng  t(i,j) là thời gian di  chuyển từ điểm i đến điểm j. Nhân viên giao hàng xuất phát từ kho tại thời điểm t0, hãy tính toán lộ trình giao hàng cho nhân viên giao hàng sao cho tổng thời gian di chuyển là ngắn nhất.
Each solution is represented by a permutation s[1], s[2], . . ., s[N] of 1, 2, . . ., N.
Input
Line 1: contains a positive integer N (1 <= N <= 1000)
Line i + 1 (i = 1, . . ., N): contains e(i), l(i) and d(i)
Line i + N + 2 (i = 0, 1, . . ., N): contains the ith row of the matrix t.
Output
Line 1: contains N
Line 2: contains s[1], s[2], . . ., s[N]
Example
Input
5
50 90 20
300 350 15
215 235 5
374 404 20
107 147 20
0 50 10 100 70 10
50 0 40 70 20 40
10 40 0 80 60 0
100 70 80 0 70 80
70 20 60 70 0 60
10 40 0 80 60 0
Output
5
1 5 3 2 4
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Customer {
    int index, startTime, endTime, duration;
};

int main()
{
    int N;
    cin >> N;

    vector<Customer> customers(N);

    // Đọc thông tin khách hàng
    for (int i = 0; i < N; ++i) {
        cin >> customers[i].startTime >> customers[i].endTime >> customers[i].duration;
        customers[i].index = i + 1;
    }

    // Đọc ma trận thời gian di chuyển
    vector<vector<int>> travelTimes(N + 1, vector<int>(N + 1));
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            cin >> travelTimes[i][j];
        }
    }

    // Sắp xếp các khách hàng dựa trên thời gian bắt đầu giao hàng
    sort(customers.begin(), customers.end(), [](const Customer& a, const Customer& b) {
        return a.startTime < b.startTime;
    });

    // Lập lộ trình giao hàng
    vector<int> deliveryRoute;
    for (const auto& customer : customers) {
        deliveryRoute.push_back(customer.index);
    }

    // In kết quả
    cout << N << endl;
    for (const auto& point : deliveryRoute) {
        cout << point << " ";
    }

    return 0;
}
