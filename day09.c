/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation
Example:
Input:
hello
Output:
olleh
Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored.*/

#include <stdio.h>

int main() {
    char str[100];
    int left = 0, right;
    char temp;

    printf("Enter the code name: ");
    scanf("%s", str);

    for (right = 0; str[right] != '\0'; right++);
    right--;

    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }

    printf("%s\n", str);

    return 0;
}
