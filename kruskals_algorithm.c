
#include <stdio.h>
int parent[10];

int find(int i) {
    while(parent[i]) i = parent[i];
    return i;
}
void uni(int i, int j) {
    parent[j] = i;
}

int main() {
    int n, i, j, min, a, b, u, v;
    int cost[10][10];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    int edges = 0, mincost = 0;
    while(edges < n - 1) {
        min = 999;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
        u = find(u);
        v = find(v);
        if(u != v) {
            uni(u, v);
            printf("Edge %d-%d cost %d\n", a, b, min);
            mincost += min;
            edges++;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Total cost = %d\n", mincost);
    return 0;
}
