/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
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

int findIntersectionValue(struct Node* head1, struct Node* head2) {
    struct Node *p1 = head1;

    while (p1 != NULL) {
        struct Node *p2 = head2;

        while (p2 != NULL) {
            if (p1->data == p2->data)
                return p1->data;
            p2 = p2->next;
        }

        p1 = p1->next;
    }

    return -1;
}

int main() {
    int n, m;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);
    printf("Enter elements of first list:\n");
    struct Node* head1 = createList(n);

    printf("Enter number of elements in second list: ");
    scanf("%d", &m);
    printf("Enter elements of second list:\n");
    struct Node* head2 = createList(m);

    int result = findIntersectionValue(head1, head2);

    if (result != -1)
        printf("%d\n", result);
    else
        printf("No Intersection\n");

    return 0;
}