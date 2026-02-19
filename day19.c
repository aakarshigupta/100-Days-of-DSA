/*Problem: Given an array of integers, find two elements whose sum is closest to zero.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the pair of elements whose sum is closest to zero
Example:
Input:
5
1 60 -10 70 -80
Output:
-10 1
Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);
    int left = 0, right = n - 1;
    int min_sum = 1000000000;
    int a, b;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            a = arr[left];
            b = arr[right];
        }

        if (sum < 0)
            left++;
        else
             right--;
    }

    printf("%d %d\n", a, b);

    return 0;
}    