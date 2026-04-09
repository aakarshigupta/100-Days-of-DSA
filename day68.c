/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int indegree[MAX];

int queue[MAX];
int front = 0, rear = -1;

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

    indegree[v]++;
}

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void topologicalSort(int n) {

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        struct Node* temp = adj[node];

        while (temp) {
            indegree[temp->vertex]--;

            if (indegree[temp->vertex] == 0)
                enqueue(temp->vertex);

            temp = temp->next;
        }
    }

    if (count != n)
        printf("\nCycle detected!\n");
}

int main() {

    int n, m, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    printf("Enter directed edges (u v):\n");

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Topological Order (Kahn's Algorithm):\n");
    topologicalSort(n);

    return 0;
}