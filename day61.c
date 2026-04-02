/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/
#include <stdio.h>

#define MAX 100

int main() {

    int n, m, u, v, type;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX] = {0};

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter 1 for Directed, 0 for Undirected: ");
    scanf("%d", &type);

    printf("Enter edges (u v):\n");

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if (type == 0)
            adj[v][u] = 1;
    }

    printf("Adjacency Matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}