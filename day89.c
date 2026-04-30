/*Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).*/
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int isPossible(int arr[], int n, int m, int maxPages) {

    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] > maxPages)
            return 0;

        if (pages + arr[i] > maxPages) {
            students++;
            pages = arr[i];
        }
        else {
            pages += arr[i];
        }
    }

    return students <= m;
}

int main() {

    int n, m;

    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    int arr[n];

    printf("Enter pages in books:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        low = max(low, arr[i]); // largest book
        high += arr[i];         // total pages
    }

    int ans = high;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1; // try smaller
        }
        else {
            low = mid + 1;
        }
    }

    printf("Minimum maximum pages: %d\n", ans);

    return 0;
}