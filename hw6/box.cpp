#include<stdio.h>

int dp[20001] = {0};
int a[31];

int max(int a, int b) {
    return a<b ? b : a;
}

int main() {
    int n, m;
    scanf("%d%d", &m, &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) {
        for(int j=m; j>=a[i]; j--) {
            dp[j] = max(dp[j], dp[j-a[i]]+a[i]);   
        }
    }
    printf("%d\n", m-dp[m]);
}