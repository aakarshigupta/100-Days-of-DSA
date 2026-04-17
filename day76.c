/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void DFS(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {

    int n, m, u, v;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges:\n");

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i);
            components++;
        }
    }

    printf("Number of connected components: %d\n", components);

    return 0;
}