#include <stdio.h>

int main() {
    int n, adj[10][10];
    int visited[10] = {0};
    int stack[10];
    int top = -1;
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

    printf("DFS Traversal: ");

    stack[++top] = start;
    visited[start] = 1;

    while (top >= 0) {
        int current = stack[top--];
        printf("%d ", current);

        for (i = n - 1; i >= 0; i--) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");

    return 0;
}
