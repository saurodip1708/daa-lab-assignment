// Fractional Knapsack Problem (Greedy)
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    double ratio;
} Item;

int cmp(const void *a, const void *b) {
    double r1 = ((Item*)a)->ratio;
    double r2 = ((Item*)b)->ratio;
    return (r1 < r2) ? 1 : (r1 > r2) ? -1 : 0;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    Item items[n];
    printf("Enter value and weight for each item:\n");
    for(int i=0;i<n;i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);
    qsort(items, n, sizeof(Item), cmp);
    double totalValue = 0.0;
    for(int i=0;i<n;i++) {
        if(W >= items[i].weight) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].ratio * W;
            break;
        }
    }
    printf("Maximum value in knapsack = %.2lf\n", totalValue);
    return 0;
}
