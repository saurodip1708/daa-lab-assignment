// Floyd-Warshall Algorithm for All-Pairs Shortest Path
#include <stdio.h>
#define MAX 100
#define INF 99999

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int dist[MAX][MAX];
    printf("Enter adjacency matrix (0 for no edge):\n");
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        scanf("%d", &dist[i][j]);
        if(i!=j && dist[i][j]==0) dist[i][j]=INF;
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
    printf("Shortest distances between every pair:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(dist[i][j]==INF) printf("INF ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}
