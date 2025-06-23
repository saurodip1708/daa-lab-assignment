// Kruskal's Algorithm for Minimum Spanning Tree
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int parent[MAX];
int find(int i) { while(parent[i]!=i) i=parent[i]; return i; }
void uni(int i, int j) { parent[find(i)] = find(j); }

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    int edges[e][3];
    printf("Enter edges (u v weight):\n");
    for(int i=0;i<e;i++) scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    for(int i=0;i<n;i++) parent[i]=i;
    // Sort edges by weight
    for(int i=0;i<e-1;i++) for(int j=0;j<e-i-1;j++) if(edges[j][2]>edges[j+1][2]) {
        int t0=edges[j][0], t1=edges[j][1], t2=edges[j][2];
        edges[j][0]=edges[j+1][0]; edges[j][1]=edges[j+1][1]; edges[j][2]=edges[j+1][2];
        edges[j+1][0]=t0; edges[j+1][1]=t1; edges[j+1][2]=t2;
    }
    int count=0, mincost=0;
    printf("Edges in MST:\n");
    for(int i=0;i<e && count<n-1;i++) {
        int u=edges[i][0], v=edges[i][1], w=edges[i][2];
        if(find(u)!=find(v)) {
            printf("%d - %d : %d\n", u, v, w);
            mincost+=w;
            uni(u,v);
            count++;
        }
    }
    printf("Total cost: %d\n", mincost);
    return 0;
}
