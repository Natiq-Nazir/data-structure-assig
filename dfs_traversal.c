
#include <stdio.h>
int adj[10][10], visited[10], n;

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 0; i < n; i++)
        if(adj[v][i] && !visited[i])
            dfs(i);
}

int main() {
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    dfs(start);
    return 0;
}
