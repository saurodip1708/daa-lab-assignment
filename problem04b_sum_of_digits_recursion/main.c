// b. Sum of digits using recursion
#include <stdio.h>
int sumDigits(int n) {
    if(n == 0) return 0;
    return n % 10 + sumDigits(n / 10);
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Sum of digits of %d is %d\n", n, sumDigits(n));
    return 0;
}
