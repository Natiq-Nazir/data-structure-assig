
#include <stdio.h>
#define INF 999
int main() {
    int n, i, j, min, u, v;
    int cost[10][10], visited[10] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0) cost[i][j] = INF;
        }
    visited[0] = 1;
    int edges = 0, mincost = 0;
    while(edges < n - 1) {
        min = INF;
        for(i = 0; i < n; i++)
            if(visited[i])
                for(j = 0; j < n; j++)
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i; v = j;
                    }
        printf("Edge %d-%d cost %d\n", u, v, min);
        mincost += min;
        visited[v] = 1;
        edges++;
    }
    printf("Total cost = %d\n", mincost);
    return 0;
}
