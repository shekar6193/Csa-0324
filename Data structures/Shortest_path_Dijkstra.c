#include <stdio.h>

int main() {
    int n, i, j, u;
    int adj[10][10];
    int dist[10];
    int visited[10];
    int inf = 9999;
    int min, next;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 0 && i != j)
                adj[i][j] = inf;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &u);

    for (i = 0; i < n; i++) {
        dist[i] = adj[u][i];
        visited[i] = 0;
    }
    visited[u] = 1;
    dist[u] = 0;

    for (i = 1; i < n; i++) {
        min = inf;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                next = j;
            }
        }

        visited[next] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[next] + adj[next][j] < dist[j]) {
                dist[j] = dist[next] + adj[next][j];
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", u);
    for (i = 0; i < n; i++) {
        if (dist[i] == inf)
            printf("%d -> %d: No path\n", u, i);
        else
            printf("%d -> %d: %d\n", u, i, dist[i]);
    }

    return 0;
}
