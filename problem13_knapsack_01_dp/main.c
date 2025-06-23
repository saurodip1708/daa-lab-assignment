// 0/1 Knapsack Problem (DP)
#include <stdio.h>
#define MAX 100
int max(int a, int b) { return (a > b) ? a : b; }

int main() {
    int n, W, wt[MAX], val[MAX];
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter values: ");
    for(int i=0;i<n;i++) scanf("%d", &val[i]);
    printf("Enter weights: ");
    for(int i=0;i<n;i++) scanf("%d", &wt[i]);
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);
    int K[n+1][W+1];
    for(int i=0;i<=n;i++) {
        for(int w=0;w<=W;w++) {
            if(i==0||w==0) K[i][w]=0;
            else if(wt[i-1]<=w) K[i][w]=max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
            else K[i][w]=K[i-1][w];
        }
    }
    printf("Maximum value: %d\n", K[n][W]);
    return 0;
}
