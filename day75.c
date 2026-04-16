/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/
#include <stdio.h>

#define MAX 1000

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefixSum = 0, maxLen = 0;

    int hash[20001];  
    for (int i = 0; i < 20001; i++)
        hash[i] = -2; 

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        int index = prefixSum + 10000;

        if (hash[index] == -2) {
            hash[index] = i;
        } else {
            int len = i - hash[index];
            if (len > maxLen)
                maxLen = len;
        }
    }

    printf("Length of longest subarray: %d\n", maxLen);

    return 0;
}