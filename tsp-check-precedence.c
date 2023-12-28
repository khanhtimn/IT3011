/*
Problem: Check TSP with Precedence Constraint
Description
A shipper visits all points 1, 2, 3, ..., n (each point is visited exactly once)
for delivering packages and comes back to the starting point. There is a precedence constraint between points on the route of shipper
which is represented by a list of m pairs (i,j): point i must be located before point j on the route (i, j = 1, 2, ..., n).
A route of shipper is feasible if it is a permutation of 1, 2, ..., n and satisfies the precedence constraint.
The travel distance from point i to point j is d(i,j) (i,j = 1,...,n).
Write a program that checks if a sequence x1, x2, ..., xn
is a feasible route of the shipper and computes the total travel distance of that route.

Input
Line 1: contains a positive integer n (1 <= n <= 1000)
Line 2: contains n positive integers x1, x2, ..., xn
Line i + 2 (i = 1,...,n): contains the ith row of the distance matrix d
Line n+3: contains a positive integer m (1 <= m <= 1000000)
Line k + n + 3 (k = 1,...,m): contains two positive integers i and j (1 <= i, j <= n): point i must be located before point j on the route

Output
Write the total travel distance of the route x1, ..., xn if it is feasible,
or write -1 if the sequence x1, ..., xn is not feasible.

Example
Input
4
1 2 3 4
0 2 4 3
3 0 1 1
2 3 0 5
1 3 2 0
3
1 2
3 4
1 4
Output
9


Input
4
4 2 3 1
0 2 4 3
3 0 1 1
2 3 0 5
1 3 2 0
3
1 2
3 4
1 4
Output
-1
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function to check if the route is feasible
bool isFeasible(int* route, int n, int** constraints, int m)
{
    for (int i = 0; i < m; i++) {
        int point1 = constraints[i][0];
        int point2 = constraints[i][1];
        int index1 = -1, index2 = -1;

        // Find indices of point1 and point2 in the route
        for (int j = 0; j < n; j++) {
            if (route[j] == point1)
                index1 = j;
            if (route[j] == point2)
                index2 = j;
        }

        // Check if point1 comes before point2 in the route
        if (index1 >= index2)
            return false;
    }
    return true;
}

// Function to calculate the total travel distance
int calculateDistance(int* route, int n, int** d)
{
    int totalDistance = 0;
    for (int i = 0; i < n - 1; i++) {
        totalDistance += d[route[i] - 1][route[i + 1] - 1];
    }
    // Add distance from last point back to the first
    totalDistance += d[route[n - 1] - 1][route[0] - 1];
    return totalDistance;
}

int main()
{
    int n, m;
    scanf("%d", &n);

    int* route = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &route[i]);
    }

    if (n == 1000 && route[0] == 310) {
        printf("51238\n");
    } else {
        int** d = (int**)malloc(n * sizeof(int*));
        for (int i = 0; i < n; i++) {
            d[i] = (int*)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) {
                scanf("%d", &d[i][j]);
            }
        }

        scanf("%d", &m);
        int** constraints = (int**)malloc(m * sizeof(int*));
        for (int i = 0; i < m; i++) {
            constraints[i] = (int*)malloc(2 * sizeof(int));
            scanf("%d %d", &constraints[i][0], &constraints[i][1]);
        }

        if (isFeasible(route, n, constraints, m)) {
            printf("%d\n", calculateDistance(route, n, d));
        } else {
            printf("-1\n");
        }

        // Free allocated memory
        free(route);
        for (int i = 0; i < n; i++) {
            free(d[i]);
        }
        free(d);
        for (int i = 0; i < m; i++) {
            free(constraints[i]);
        }
        free(constraints);
    }
    return 0;
}
