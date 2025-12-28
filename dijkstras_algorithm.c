
#include <stdio.h>
#define INF 999
int main() {
    int n, source;
    int cost[10][10], dist[10], visited[10] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    printf("Enter source vertex: ");
    scanf("%d", &source);
    for(int i = 0; i < n; i++)
        dist[i] = cost[source][i];
    visited[source] = 1;
    for(int count = 1; count < n; count++) {
        int min = INF, u;
        for(int i = 0; i < n; i++)
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        visited[u] = 1;
        for(int v = 0; v < n; v++)
            if(!visited[v] && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
    }
    printf("Shortest distances from source:\n");
    for(int i = 0; i < n; i++)
        printf("%d -> %d = %d\n", source, i, dist[i]);
    return 0;
}
