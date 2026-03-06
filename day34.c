/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node* temp = top;
    int value = temp->data;

    top = top->next;
    free(temp);

    return value;
}

int main() {

    char postfix[100];
    int i = 0;

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    char *token = strtok(postfix, " ");

    while (token != NULL) {

        if (isdigit(token[0])) {
            push(atoi(token));
        }
        else {
            int op2 = pop();
            int op1 = pop();
            int result;

            switch (token[0]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    printf("%d\n", pop());

    return 0;
}