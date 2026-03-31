/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int postIndex;

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int postorder[], int start, int end) {

    if (start > end)
        return NULL;

    int rootVal = postorder[postIndex--];
    struct Node* root = newNode(rootVal);

    int index = search(inorder, start, end, rootVal);

    root->right = buildTree(inorder, postorder, index + 1, end);
    root->left = buildTree(inorder, postorder, start, index - 1);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {

    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    printf("Enter postorder traversal:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1);

    printf("Preorder traversal:\n");
    preorder(root);

    return 0;
}