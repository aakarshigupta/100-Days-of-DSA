/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements
Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"
Example:
Input:
3
1 0 0
0 1 0
0 0 1
Output:
Identity Matrix*/
#include <stdio.h>

int main() {
    int n;
    int a[100][100];
    int isIdentity = 1;

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j && a[i][j] != 1) || (i != j && a[i][j] != 0)) {
                isIdentity = 0;
                break;
            }
        }
        if (!isIdentity)
            break;
    }

    if (isIdentity)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}
