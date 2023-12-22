/*
Problem: Longest 1 sequence
Description
Given a binary sequence, find the longest  subsequence containing only bit 1s (called 1-subsequence)
Input
Unique line containing the binary sequence
Output
The length of the longest 1-subsequence
*/
#include <stdio.h>

int main()
{
    char currentBit;
    int currentLength = 0;
    int maxLength = 0;

    while (1) {
        currentBit = getchar();
        if (currentBit == '1') {
            currentLength++;
        } else if (currentBit == '0' || currentBit == '\n') {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 0;
        }

        if (currentBit == '\n') {
            break;
        }
    }

    printf("%d\n", maxLength);

    return 0;
}
