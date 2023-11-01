#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int a[110][3];
int dp[110][1010] = {0};

int main() {
    int t, m;
    scanf("%d%d", &t, &m);
    for(int i=1; i<=m; i++) {
        scanf("%d%d", &a[i][0], &a[i][1]);
    }
    for(int i=1; i<=m; i++) {
        for(int j=0; j<=t; j++) {
            if(j-a[i][0] >= 0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i][0]]+a[i][1]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    printf("%d\n", dp[m][t]);
}