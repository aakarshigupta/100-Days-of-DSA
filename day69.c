/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue (Dijkstra's Algorithm).*/
#include <stdio.h>
#include <limits.h>

#define MAX 100

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, minIndex;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[MAX][MAX], int n, int src) {

    int dist[MAX], visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {

        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {

            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from source:\n");
    for (int i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

int main() {

    int n, m, u, v, w, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX] = {0};

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; 
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}