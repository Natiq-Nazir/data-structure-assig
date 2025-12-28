
#include <stdio.h>
int adj[10][10], visited[10], n;

void dfs(int v) {
    visited[v] = 1;
    for(int i = 0; i < n; i++)
        if(adj[v][i] && !visited[i])
            dfs(i);
}

int main() {
    int count = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
            count++;
        }
    }
    printf("Connected Components = %d\n", count);
    return 0;
}
