/*
Problem: Count Solutions TSP
Description
There are N cities. The distance between city i and city j is c(i,j), forall i,j = 1,. . .,N. A tour is define to be a permutation x1, x2, . . . , xN of 1, 2,..., N (in which x1 is always fixed by 1) and its length is defined to be c(x1, x2) + c(x2, x3) + . . . + c(xN-1, xN) + c(xN, x1)$. Given a positive integer M. Compute how many tours whose length is less than or equal to M.
Input

    Line 1 contains N và M (1 <= N <= 15, 1 <= M <= 1000000).
    Line i+1 (forall i = 1,. . ., N) contains the ith row of the matrix c

Output
Write the number of tours whose length is less than or equal to M.
Example
Input
4  10
0 1 2 6
1 0 5 4
2 5 0 3
6 4 3 0
Output
2
*/
#include <stdio.h>

#define MAX_N 15

int N, M;
int c[MAX_N][MAX_N];
int visited[MAX_N];
int permutation[MAX_N];
int count = 0;

void calculateTours(int currentCity, int tourLength)
{
    if (currentCity == N) {
        if (tourLength + c[permutation[N - 1]][0] <= M) {
            count++;
        }
        return;
    }

    for (int nextCity = 1; nextCity < N; nextCity++) {
        if (!visited[nextCity]) {
            visited[nextCity] = 1;
            permutation[currentCity] = nextCity;
            int newLength = tourLength + c[permutation[currentCity - 1]][nextCity];
            calculateTours(currentCity + 1, newLength);
            visited[nextCity] = 0;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    visited[0] = 1;
    permutation[0] = 0;
    calculateTours(1, 0);

    printf("%d\n", count);

    return 0;
}
/*
* Exceed time limit for input:
12 30
0 1 3 5 9 10 5 7 10 5 2 3
1 0 6 2 3 1 9 5 1 8 10 1
3 8 0 7 8 10 8 6 1 8 4 5
10 3 1 0 5 2 1 10 2 1 4 6
3 6 5 10 0 10 7 3 7 2 6 8
10 5 6 5 9 0 9 5 4 7 2 5
1 10 2 7 4 5 0 3 6 3 4 7
5 1 8 5 5 8 6 0 2 10 3 5
10 6 9 4 3 10 10 4 0 1 5 5
1 8 1 2 1 4 1 4 10 0 9 5
8 5 4 3 3 5 4 8 1 3 0 6
5 8 8 4 3 9 8 1 7 8 8 0

&&


12 30
0 6 6 2 6 2 6 5 8 1 4 9
8 0 4 4 10 5 7 2 4 3 1 1
8 8 0 7 8 2 3 7 4 1 3 10
4 4 6 0 2 9 9 3 6 3 2 8
6 6 1 1 0 1 4 3 9 9 9 8
5 9 9 5 3 0 1 8 9 7 8 3
4 6 8 10 9 6 0 5 4 4 5 3
5 1 2 5 1 3 6 0 7 7 6 5
2 7 4 8 9 5 9 5 0 3 3 1
6 2 9 4 5 3 2 5 8 0 8 1
2 1 6 9 8 4 8 5 8 10 0 8
4 4 10 4 3 7 1 7 4 5 3 0

*/
