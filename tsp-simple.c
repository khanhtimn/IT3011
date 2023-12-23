/*
Problem: TSP
Description
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  A person departs from city 1, visits each city 2, 3, ..., n exactly once and comes back to city 1. Find the itinerary for that person so that the total travel distance is minimal.
Input

    Line 1: a positive integer n (1 <= n <= 20)
    Linr i+1 (i = 1, . . ., n): contains the ith row of the distance matrix x (elements are separated by a SPACE character)

Output
Write the total travel distance of the optimal itinerary found.
Example
Input
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
Output
7
*/
#include <limits.h>
#include <stdio.h>

int n;
int dist[21][21];
int memo[21][1 << 21];

int tsp(int pos, int bitmask)
{
    if (bitmask == ((1 << n) - 1))
        return dist[pos][0];

    if (memo[pos][bitmask] != -1)
        return memo[pos][bitmask];

    int minCost = INT_MAX;
    for (int nxt = 0; nxt < n; nxt++) {
        if (nxt != pos && !(bitmask & (1 << nxt))) {
            int newCost = dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt));
            minCost = (newCost < minCost) ? newCost : minCost;
        }
    }

    memo[pos][bitmask] = minCost;
    return minCost;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < (1 << n); j++)
            memo[i][j] = -1;

    printf("%d\n", tsp(0, 1));
    return 0;
}
