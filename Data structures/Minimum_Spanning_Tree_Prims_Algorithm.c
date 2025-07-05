#include <stdio.h>

int main() {
    int n;
    int cost[10][10];
    int visited[10];
    int i, j;
    int edges = 0;
    int minCost = 0;
    int u = 0, v = 0;
    int min;
    int inf = 9999;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = inf;
        }
    }

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[0] = 1;

    printf("Edges in the Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = inf;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        visited[v] = 1;
        printf("%d - %d : %d\n", u, v, min);
        minCost += min;
        edges++;
    }

    printf("Total cost of MST = %d\n", minCost);

    return 0;
}
