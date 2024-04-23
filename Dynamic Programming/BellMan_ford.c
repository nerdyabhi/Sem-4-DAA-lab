#include <stdio.h>
#define n 7
#define INF 9999

int min(int a, int b) {
    if (a <= b)
        return a;
    return b;
}

void print(int arr[], int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("\n------------------Bellman-Ford algorithm----------------------- \n");
    int i = 0, j = 0, k = 0;

    int cost[n][n] = {
        {0, 6, 5, 5, INF, INF, INF},
        {INF, 0, INF, INF, -1, INF, INF},
        {INF, -2, 0, INF, 1, INF, INF},
        {INF, INF, INF, 0, INF, -1, INF},
        {INF, INF, INF, INF, 0, INF, 3},
        {INF, INF, INF, INF, INF, 0, 3},
        {INF, INF, INF, INF, INF, INF, 0}
    };

    int v = 0;
    int dist[n];
    for (i = 0; i < n; i++) dist[i] = INF;
    dist[v] = 0;

    // Relax all edges repeatedly
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (cost[j][k] != INF) {
                    dist[k] = min(dist[k], dist[j] + cost[j][k]);
                }
            }
        }
    }

    // Check for negative cycles
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (cost[j][k] != INF) {
                    if (dist[k] > dist[j] + cost[j][k]) {
                        printf("Graph contains negative cycle!\n");
                        return 0;
                    }
                }
            }
        }
    }

    print(dist, n);

    return 0;
}
