#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> arr;
int dp[120][120]={1};

int main() {
    int x;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        arr.push_back(x);
    }
    for(int i=0; i<n; i++) 
        arr.push_back(arr[i]);

    for(int len=2; len<=n+1; len++) {
        for(int left=0l left)
    }
    int ans = 0;
    for(int i=1; i<=n; i++) 
        ans = max(ans, dp[i][n+i-1]);

    printf("%d\n", ans);
}