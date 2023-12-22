/*
Problem: Disjoint Segment
Description
Given a set of segments X = {(a1, b1), . . . , (an, bn)} in which ai < bi are coordinates of the segment i on a line, i = 1, …, n.  Find a subset of X having largest cardinality in which no two segments of the subset intersect
Input

    Line 1: contains a positive integer n (1 <= n <= 100000)
    Line i+1 (i= 1,...,n): contains ai and bi (0 <= ai <= bi <= 1000000)

Output
Number of segments in the solution found.
Example
Input
6
0 10
3 7
6 14
9 11
12 15
17 19

Output
4
*/
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the segments
typedef struct {
    int start;
    int end;
} Segment;

// Comparator function for sorting the segments
int compareSegments(const void* a, const void* b)
{
    Segment* segA = (Segment*)a;
    Segment* segB = (Segment*)b;
    return segA->end - segB->end;
}

int main()
{
    int n, i;
    scanf("%d", &n);

    Segment segments[n];
    for (i = 0; i < n; i++) {
        scanf("%d %d", &segments[i].start, &segments[i].end);
    }

    // Sort the segments by their end points
    qsort(segments, n, sizeof(Segment), compareSegments);

    // Greedy algorithm to find the maximum number of non-overlapping segments
    int count = 0;
    int lastEnd = -1;
    for (i = 0; i < n; i++) {
        if (segments[i].start >= lastEnd) {
            lastEnd = segments[i].end;
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
/*
 * Failed 2 test case for arbitraily large input?
 */
