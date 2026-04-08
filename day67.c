/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

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
}

void push(int v) {
    stack[++top] = v;
}

void DFS(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];

    while (temp) {
        if (!visited[temp->vertex])
            DFS(temp->vertex);
        temp = temp->next;
    }

    push(v);
}

void topologicalSort(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            DFS(i);
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {

    int n, m, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter directed edges (u v):\n");

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Topological Order:\n");
    topologicalSort(n);

    return 0;
}