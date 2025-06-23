// Job Sequencing Problem (Greedy)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[10];
    int deadline;
    int profit;
} Job;

int cmp(const void *a, const void *b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

int main() {
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    Job jobs[n];
    printf("Enter job id, deadline, and profit for each job:\n");
    for(int i=0;i<n;i++) {
        scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }
    qsort(jobs, n, sizeof(Job), cmp);
    int maxDeadline = 0;
    for(int i=0;i<n;i++) if(jobs[i].deadline > maxDeadline) maxDeadline = jobs[i].deadline;
    char result[maxDeadline][10];
    int slot[maxDeadline];
    for(int i=0;i<maxDeadline;i++) slot[i]=0;
    int totalProfit = 0;
    for(int i=0;i<n;i++) {
        for(int j=jobs[i].deadline-1;j>=0;j--) {
            if(!slot[j]) {
                slot[j]=1;
                strcpy(result[j], jobs[i].id);
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    printf("Selected jobs: ");
    for(int i=0;i<maxDeadline;i++) if(slot[i]) printf("%s ", result[i]);
    printf("\nTotal profit: %d\n", totalProfit);
    return 0;
}
