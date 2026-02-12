/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/

#include <stdio.h>

int main() {
    char str[100];
    int left = 0, right = 0;
    int isPalindrome = 1;

    printf("Enter string: ");
    scanf("%s", str);

    while (str[right] != '\0') {
        right++;
    }
    right--;

    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
