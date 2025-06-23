// Dijkstra's Algorithm for Shortest Path
#include <stdio.h>
#define MAX 100
#define INF 99999

int main() {
    int n, src;
    int cost[MAX][MAX], dist[MAX], visited[MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 for no edge):\n");
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        scanf("%d", &cost[i][j]);
        if(cost[i][j]==0 && i!=j) cost[i][j]=INF;
    }
    printf("Enter source vertex: ");
    scanf("%d", &src);
    for(int i=0;i<n;i++) { dist[i]=cost[src][i]; visited[i]=0; }
    dist[src]=0; visited[src]=1;
    for(int count=1;count<n;count++) {
        int min=INF, u=-1;
        for(int i=0;i<n;i++) if(!visited[i] && dist[i]<min) { min=dist[i]; u=i; }
        if(u==-1) break;
        visited[u]=1;
        for(int v=0;v<n;v++) if(!visited[v] && dist[u]+cost[u][v]<dist[v]) dist[v]=dist[u]+cost[u][v];
    }
    printf("Shortest distances from %d:\n", src);
    for(int i=0;i<n;i++) printf("To %d: %d\n", i, dist[i]);
    return 0;
}
