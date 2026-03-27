/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *left, *right;
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

void rightView(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* node = queue[front++];

            if (i == size - 1)
                printf("%d ", node->data);

            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }
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

    printf("Right view of binary tree:\n");
    rightView(root);

    return 0;
}