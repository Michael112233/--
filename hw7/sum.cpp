#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int dp[200010] = {0};
int pos[200010] = {0};
vector<int> a;

int main() {
    int n, x, T, cnt=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        a.push_back(x);
    }
    
    dp[n-1] = a[n-1];
    pos[n-1] = n-1;
    for(int i=n-2; i>=0; i--) {
        if(dp[i+1] >= 0) {
            dp[i] = dp[i+1] + a[i];
            pos[i] = pos[i+1];
        }
        else {
            dp[i] = a[i]; 
            pos[i] = i;
        }
    }

    int ans = -100000;
    int maxPos = 0;

    for(int i=0; i<n; i++) {
        if(ans < dp[i]) {
            ans = dp[i];
            maxPos = i;
        }
    }

    // printf("Case %d:\n", ++cnt);
    // printf("%d %d %d\n", ans, maxPos+1, pos[maxPos]+1);
    printf("%d\n", ans);
}