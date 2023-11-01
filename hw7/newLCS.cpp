#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

int mod = 1e8;

char str1[5010];
char str2[5010];

int num[2][5010] = {0};
int dp[2][5010] = {0};

int len1, len2;

void init() {
    len1 = strlen(str1)-1;
    len2 = strlen(str2)-1;

    for(int i=0; i<=1; i++) {
        num[i][0] = 1;
    }   

    for(int i=0; i<=len2; i++) {
        num[0][i] = 1;
        dp[0][i] = 0;
    }
}

int main() {
    scanf("%s", str1);
    scanf("%s", str2);

    init();

    int t = 0;

    for(int i=0; i<len1; i++, t^=1) {
        for(int j=0; j<len2; j++) {
            num[t^1][j+1] = 0;
            if(str1[i] == str2[j]) {
                dp[t^1][j+1] = dp[t][j] + 1;
                num[t^1][j+1] = num[t][j];
            } else 
                dp[t^1][j+1] = max(dp[t^1][j], dp[t][j+1]);
            if(dp[t^1][j] == dp[t^1][j+1]) 
                num[t^1][j+1] += num[t^1][j];
            if(dp[t][j+1] == dp[t^1][j+1]) 
                num[t^1][j+1] += num[t][j+1];
            if(str1[i] != str2[j] && dp[t^1][j+1] == dp[t][j]) 
                num[t^1][j+1] -= num[t][j];
            num[t^1][j+1] %= mod;
        }
    }

    // for(int i=0; i<=1; i++) {
    //     for(int j=0; j<=len2; j++) {
    //         printf("%d ", num[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n%d\n", dp[t][len2], num[t][len2]);
}