// N-Queens Problem (Backtracking)
#include <stdio.h>
#define MAX 20
int board[MAX][MAX], n;

int isSafe(int row, int col) {
    for(int i=0;i<col;i++) if(board[row][i]) return 0;
    for(int i=row,j=col;i>=0&&j>=0;i--,j--) if(board[i][j]) return 0;
    for(int i=row,j=col;i<n&&j>=0;i++,j--) if(board[i][j]) return 0;
    return 1;
}
int solve(int col) {
    if(col>=n) return 1;
    for(int i=0;i<n;i++) {
        if(isSafe(i,col)) {
            board[i][col]=1;
            if(solve(col+1)) return 1;
            board[i][col]=0;
        }
    }
    return 0;
}
void printBoard() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) printf("%d ",board[i][j]);
        printf("\n");
    }
}
int main() {
    printf("Enter value of N: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) board[i][j]=0;
    if(solve(0)) printBoard();
    else printf("No solution exists!\n");
    return 0;
}
