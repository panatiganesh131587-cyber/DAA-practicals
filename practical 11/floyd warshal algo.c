#include <stdio.h>
#define MAX 20
#define INF 999999
void printMatrix(int dist[MAX][MAX], int V) {
    printf("    ");
    for (int j = 0; j < V; j++) {
        printf("%6d", j);
    }
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%3d ", i);
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF) {
                printf("%6s", "INF");
            } else {
                printf("%6d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int V;
    int dist[MAX][MAX];

    printf("Enter number of vertices (max %d): ", MAX);
    if (scanf("%d", &V) != 1 || V <= 0 || V > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("\nEnter the adjacency/weight matrix (%d x %d).\n", V, V);
    printf("Use -1 (or a large number like 999999) if there is no direct edge between i and j:\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int w;
            scanf("%d", &w);
            if (i == j) {
                dist[i][j] = 0;
            } else if (w < 0 || w >= INF) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = w;
            }
        }
    }

    printf("\n--- Initial Matrix (D^0) ---\n");
    printMatrix(dist, V);
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        printf("\n--- After allowing vertex %d as intermediate (D^%d) ---\n", k, k + 1);
        printMatrix(dist, V);
    }
    int hasNegativeCycle = 0;
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            hasNegativeCycle = 1;
            break;
        }
    }

    if (hasNegativeCycle) {
        printf("\nWarning: Negative weight cycle detected in the graph.\n");
    }

    printf("\n--- Final All-Pairs Shortest Path Matrix ---\n");
    printMatrix(dist, V);

    return 0;
}
