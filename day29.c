/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL)
        return head;

    int n = getLength(head);
    k = k % n;

    if (k == 0)
        return head;

    struct Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head;

    int steps = n - k;
    temp = head;

    for (int i = 1; i < steps; i++)
        temp = temp->next;

    head = temp->next;
    temp->next = NULL;

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    struct Node* head = createList(n);

    printf("Enter k: ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}