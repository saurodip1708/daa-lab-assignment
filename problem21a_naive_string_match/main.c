// Naive String Matching
#include <stdio.h>
#include <string.h>
int main() {
    char txt[100], pat[100];
    printf("Enter text: ");
    scanf("%s", txt);
    printf("Enter pattern: ");
    scanf("%s", pat);
    int n = strlen(txt), m = strlen(pat), found = 0;
    for(int i=0;i<=n-m;i++) {
        int j;
        for(j=0;j<m;j++) if(txt[i+j]!=pat[j]) break;
        if(j==m) { printf("Pattern found at index %d\n", i); found=1; }
    }
    if(!found) printf("Pattern not found\n");
    return 0;
}
