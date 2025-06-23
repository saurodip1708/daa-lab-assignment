// KMP String Matching
#include <stdio.h>
#include <string.h>
void computeLPS(char* pat, int m, int* lps) {
    int len=0; lps[0]=0;
    int i=1;
    while(i<m) {
        if(pat[i]==pat[len]) lps[i++]=++len;
        else if(len) len=lps[len-1];
        else lps[i++]=0;
    }
}
int main() {
    char txt[100], pat[100];
    printf("Enter text: ");
    scanf("%s", txt);
    printf("Enter pattern: ");
    scanf("%s", pat);
    int n=strlen(txt), m=strlen(pat), lps[m], i=0, j=0, found=0;
    computeLPS(pat, m, lps);
    while(i<n) {
        if(pat[j]==txt[i]) { i++; j++; }
        if(j==m) { printf("Pattern found at index %d\n", i-j); found=1; j=lps[j-1]; }
        else if(i<n && pat[j]!=txt[i]) {
            if(j) j=lps[j-1]; else i++;
        }
    }
    if(!found) printf("Pattern not found\n");
    return 0;
}
