// Strassen's Algorithm for Matrix Multiplication
#include <stdio.h>
#include <stdlib.h>
#define MAX 4 // For demonstration, use 2^n size (e.g., 2, 4, 8...)

void add(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] + B[i][j];
}
void sub(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] - B[i][j];
}
void strassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    if(n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int mid = n/2;
    int a11[MAX][MAX], a12[MAX][MAX], a21[MAX][MAX], a22[MAX][MAX];
    int b11[MAX][MAX], b12[MAX][MAX], b21[MAX][MAX], b22[MAX][MAX];
    int c11[MAX][MAX], c12[MAX][MAX], c21[MAX][MAX], c22[MAX][MAX];
    int m1[MAX][MAX], m2[MAX][MAX], m3[MAX][MAX], m4[MAX][MAX], m5[MAX][MAX], m6[MAX][MAX], m7[MAX][MAX];
    int t1[MAX][MAX], t2[MAX][MAX];
    for(int i=0;i<mid;i++) for(int j=0;j<mid;j++) {
        a11[i][j]=A[i][j]; a12[i][j]=A[i][j+mid];
        a21[i][j]=A[i+mid][j]; a22[i][j]=A[i+mid][j+mid];
        b11[i][j]=B[i][j]; b12[i][j]=B[i][j+mid];
        b21[i][j]=B[i+mid][j]; b22[i][j]=B[i+mid][j+mid];
    }
    add(a11, a22, t1, mid); add(b11, b22, t2, mid); strassen(t1, t2, m1, mid);
    add(a21, a22, t1, mid); strassen(t1, b11, m2, mid);
    sub(b12, b22, t2, mid); strassen(a11, t2, m3, mid);
    sub(b21, b11, t2, mid); strassen(a22, t2, m4, mid);
    add(a11, a12, t1, mid); strassen(t1, b22, m5, mid);
    sub(a21, a11, t1, mid); add(b11, b12, t2, mid); strassen(t1, t2, m6, mid);
    sub(a12, a22, t1, mid); add(b21, b22, t2, mid); strassen(t1, t2, m7, mid);
    add(m1, m4, t1, mid); sub(t1, m5, t2, mid); add(t2, m7, c11, mid);
    add(m3, m5, c12, mid);
    add(m2, m4, c21, mid);
    add(m1, m3, t1, mid); sub(t1, m2, t2, mid); add(t2, m6, c22, mid);
    for(int i=0;i<mid;i++) for(int j=0;j<mid;j++) {
        C[i][j]=c11[i][j]; C[i][j+mid]=c12[i][j];
        C[i+mid][j]=c21[i][j]; C[i+mid][j+mid]=c22[i][j];
    }
}
int main() {
    int n;
    printf("Enter matrix size (2 or 4): ");
    scanf("%d", &n);
    if(n!=2 && n!=4) { printf("Only 2 or 4 supported.\n"); return 1; }
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    printf("Enter elements of matrix A:\n");
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&A[i][j]);
    printf("Enter elements of matrix B:\n");
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&B[i][j]);
    strassen(A, B, C, n);
    printf("Resultant matrix C = A*B:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) printf("%d ",C[i][j]);
        printf("\n");
    }
    return 0;
}
