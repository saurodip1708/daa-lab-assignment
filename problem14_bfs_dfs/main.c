// BFS and DFS for Graph Traversal
#include <stdio.h>
#define MAX 100
int adj[MAX][MAX], visited[MAX], n;

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for(int i=0;i<n;i++) if(adj[v][i] && !visited[i]) dfs(i);
}

void bfs(int start) {
    int queue[MAX], front=0, rear=0;
    for(int i=0;i<n;i++) visited[i]=0;
    queue[rear++] = start;
    visited[start]=1;
    while(front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for(int i=0;i<n;i++) {
            if(adj[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i]=1;
            }
        }
    }
}

int main() {
    int e, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for(int i=0;i<e;i++) {
        printf("Edge %d (u v): ", i+1);
        scanf("%d %d", &u, &v);
        adj[u][v]=adj[v][u]=1;
    }
    printf("Enter start vertex for DFS: ");
    scanf("%d", &start);
    for(int i=0;i<n;i++) visited[i]=0;
    printf("DFS: "); dfs(start); printf("\n");
    printf("Enter start vertex for BFS: ");
    scanf("%d", &start);
    printf("BFS: "); bfs(start); printf("\n");
    return 0;
}
