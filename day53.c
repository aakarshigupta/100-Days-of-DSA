/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *left, *right;
};

struct Pair {
    struct Node* node;
    int hd;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {

    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    int j = 1;

    for (int i = 0; i < n && j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n)
                nodes[i]->left = nodes[j++];
            if (j < n)
                nodes[i]->right = nodes[j++];
        }
    }

    return nodes[0];
}

void verticalOrder(struct Node* root) {

    if (root == NULL)
        return;

    struct Pair queue[MAX];
    int front = 0, rear = 0;

    int column[200][100];
    int count[200] = {0};

    int offset = 100;
    int min = 0, max = 0;

    queue[rear++] = (struct Pair){root, 0};

    while (front < rear) {

        struct Pair current = queue[front++];
        struct Node* node = current.node;
        int hd = current.hd;

        int index = hd + offset;

        column[index][count[index]++] = node->data;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        if (node->left != NULL)
            queue[rear++] = (struct Pair){node->left, hd - 1};

        if (node->right != NULL)
            queue[rear++] = (struct Pair){node->right, hd + 1};
    }

    for (int i = min; i <= max; i++) {
        int index = i + offset;
        for (int j = 0; j < count[index]; j++) {
            printf("%d ", column[index][j]);
        }
        printf("\n");
    }
}

int main() {

    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order traversal (-1 for NULL):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}