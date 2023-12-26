/*
Problem: Hash Over Strings
Description
Given a string s[1…k] which is a sequence of characters taken from {‘a’, . . ., ‘z’}. Given a positive integer m, the hash code of s is defined by the formula:
H(s) =  (s[1]*256k-1 + s[2]*256k-2 + . . . + s[k]*2560 ) mod m  (the contant integer m is a parameter)
Given a sequence of strings k1, k2, …, kn, compute the corresponding hash codes
Input
Line 1: n and m (1 <= n,m <= 100000)
Line i+1 (i = 1,2,…,n): contains the string ki (the length of each string is less than or equal to 200)
Output
Each line contains the corresponding hash code of n given strings
Example
Input
4 1000
a
ab
abc
abcd
Output
97
930
179
924
*/
#include <stdio.h>
#include <string.h>

// Function to compute the hash code of a string
unsigned long hashString(char* str, int m)
{
    int k = strlen(str);
    unsigned long hash = 0;
    for (int i = 0; i < k; i++) {
        hash = (hash * 256 + str[i]) % m;
    }
    return hash;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m); // Reading n and m

    char str[201]; // Assuming max length of string is 200
    for (int i = 0; i < n; i++) {
        scanf("%s", str); // Reading each string
        printf("%lu\n", hashString(str, m)); // Printing the hash code
    }

    return 0;
}
