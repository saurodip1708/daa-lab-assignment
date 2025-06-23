// Prim's Algorithm for Minimum Spanning Tree
#include <stdio.h>
#define INF 99999
#define MAX 100

int main() {
    int n, cost[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (use 0 for no edge):\n");
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        scanf("%d", &cost[i][j]);
        if(cost[i][j]==0) cost[i][j]=INF;
    }
    int selected[MAX]={0}, edge_count=0, mincost=0;
    selected[0]=1;
    printf("Edges in MST:\n");
    while(edge_count < n-1) {
        int min=INF, x=0, y=0;
        for(int i=0;i<n;i++) if(selected[i])
            for(int j=0;j<n;j++) if(!selected[j] && cost[i][j])
                if(min > cost[i][j]) { min=cost[i][j]; x=i; y=j; }
        printf("%d - %d : %d\n", x, y, cost[x][y]);
        mincost += cost[x][y];
        selected[y]=1;
        edge_count++;
    }
    printf("Total cost: %d\n", mincost);
    return 0;
}
