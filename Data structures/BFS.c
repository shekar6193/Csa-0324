#include <stdio.h>

int main() {
    int n, adj[10][10];
    int visited[10] = {0};
    int queue[10];
    int front = 0, rear = 0;
    int start, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter start vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");

    return 0;
}
