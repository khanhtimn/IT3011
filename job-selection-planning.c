/*
Problem: Job Selection & Planning
Description
Given n jobs J = {1,. . .,n}. Each job i has a deadline d(i) and associated profit p(i) if the job is finished before the deadline. Every job takes the single unit of time, so the minimum possible deadline for any job is 1. It is also noted that no more than one job can be executed at a time.
Select and schedule a subset of jobs of J such that the total profits is maximal.
Input

    Line 1: contains a positive integer n (1 <= n <= 105)
    Line i+1 (i=1,. . . ,n) contains d(i) and p(i) (1 <= d(i), p(i) <= 105)

Output

    Write to total profits obtained from the subset of jobs found.

Example
Input
6
3 10
2 40
6 70
3 50
5 80
1 60
Output
300
*/
#include <stdio.h>
#include <stdlib.h>

// Structure to store job details
typedef struct {
    int deadline;
    int profit;
} Job;

// Function to compare jobs based on profit
int compare(const void* a, const void* b)
{
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

// Main function to schedule jobs and calculate total profit
int main()
{
    int n, i, j, maxDeadline = 0;
    scanf("%d", &n);
    Job jobs[n];
    int timeSlot[n];

    // Reading job details
    for (i = 0; i < n; i++) {
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
        maxDeadline = (jobs[i].deadline > maxDeadline) ? jobs[i].deadline : maxDeadline;
    }

    // Sort jobs based on profit
    qsort(jobs, n, sizeof(Job), compare);

    // Initialize time slots to -1
    for (i = 0; i < n; i++) {
        timeSlot[i] = -1;
    }

    // Assign jobs to time slots
    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (j < n && timeSlot[j] == -1) {
                timeSlot[j] = i;
                break;
            }
        }
    }

    // Calculate total profit
    int totalProfit = 0;
    for (i = 0; i < n; i++) {
        if (timeSlot[i] != -1) {
            totalProfit += jobs[timeSlot[i]].profit;
        }
    }

    // Output the total profit
    printf("%d\n", totalProfit);

    return 0;
}
