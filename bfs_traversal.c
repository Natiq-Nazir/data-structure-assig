
#include <stdio.h>
int adj[10][10], visited[10], queue[10];
int front = -1, rear = -1, n;

void bfs(int start) {
    visited[start] = 1;
    queue[++rear] = start;
    while(front != rear) {
        start = queue[++front];
        printf("%d ", start);
        for(int i = 0; i < n; i++) {
            if(adj[start][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
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
    bfs(start);
    return 0;
}
