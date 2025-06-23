// c. Decimal to binary using recursion
#include <stdio.h>
void decToBinary(int n) {
    if(n == 0) return;
    decToBinary(n / 2);
    printf("%d", n % 2);
}
int main() {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    if(n == 0) printf("0");
    else decToBinary(n);
    printf("\n");
    return 0;
}
