// Fibonacci: Naive Recursion and Dynamic Programming
#include <stdio.h>
#include <time.h>

long long fib_naive(int n) {
    if(n <= 1) return n;
    return fib_naive(n-1) + fib_naive(n-2);
}

long long fib_dp(int n) {
    long long f[n+2];
    f[0]=0; f[1]=1;
    for(int i=2;i<=n;i++) f[i]=f[i-1]+f[i-2];
    return f[n];
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    clock_t t1 = clock();
    long long res1 = fib_naive(n);
    clock_t t2 = clock();
    long long res2 = fib_dp(n);
    clock_t t3 = clock();
    printf("Naive Recursion: %lld (Time: %.6fs)\n", res1, (double)(t2-t1)/CLOCKS_PER_SEC);
    printf("DP Approach: %lld (Time: %.6fs)\n", res2, (double)(t3-t2)/CLOCKS_PER_SEC);
    return 0;
}
