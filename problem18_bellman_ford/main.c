// Bellman-Ford Algorithm for Shortest Path (handles negative edges)
#include <stdio.h>
#define MAX 100
#define INF 99999

typedef struct { int u, v, w; } Edge;

int main() {
    int n, e, src;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    Edge edges[e];
    printf("Enter edges (u v weight):\n");
    for(int i=0;i<e;i++) scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    printf("Enter source vertex: ");
    scanf("%d", &src);
    int dist[n];
    for(int i=0;i<n;i++) dist[i]=INF;
    dist[src]=0;
    for(int i=1;i<n;i++) for(int j=0;j<e;j++)
        if(dist[edges[j].u]!=INF && dist[edges[j].u]+edges[j].w<dist[edges[j].v])
            dist[edges[j].v]=dist[edges[j].u]+edges[j].w;
    // Check for negative cycles
    int neg=0;
    for(int j=0;j<e;j++)
        if(dist[edges[j].u]!=INF && dist[edges[j].u]+edges[j].w<dist[edges[j].v]) neg=1;
    if(neg) printf("Graph contains negative weight cycle!\n");
    else for(int i=0;i<n;i++) printf("To %d: %d\n", i, dist[i]);
    return 0;
}
