#include <stdio.h>

int find(int parent[], int a) {
    while (parent[a] != a)
        a = parent[a];
    return a;
}

void unionSets(int parent[], int a, int b) {
    int rootA = find(parent, a);
    int rootB = find(parent, b);
    parent[rootB] = rootA;
}

int main() {
    int n, e, i, j;
    int u, v, w;
    int parent[20];
    int edges[20][3];
    int temp[3];
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < e - 1; i++) {
        for (j = i + 1; j < e; j++) {
            if (edges[i][2] > edges[j][2]) {
                temp[0] = edges[i][0];
                temp[1] = edges[i][1];
                temp[2] = edges[i][2];
                edges[i][0] = edges[j][0];
                edges[i][1] = edges[j][1];
                edges[i][2] = edges[j][2];
                edges[j][0] = temp[0];
                edges[j][1] = temp[1];
                edges[j][2] = temp[2];
            }
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");

    int count = 0;
    for (i = 0; i < e && count < n - 1; i++) {
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];

        if (find(parent, u) != find(parent, v)) {
            printf("%d - %d : %d\n", u, v, w);
            unionSets(parent, u, v);
            totalCost += w;
            count++;
        }
    }

    printf("Total cost of MST = %d\n", totalCost);

    return 0;
}
