#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

char str1[5010];
char str2[5010];

int num[5010][5010] = {0};
int dp[5010][5010] = {0};

int len1, len2;

void init() {
    len1 = strlen(str1)-1;
    len2 = strlen(str2)-1;

    for(int i=0; i<=len1; i++) {
        num[i][0] = 1;
        dp[i][0] = 0;
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

    for(int i=0; i<len1; i++) {
        for(int j=0; j<len2; j++) {
            num[i+1][j+1] = 0;
            if(str1[i] == str2[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
                num[i+1][j+1] = num[i][j];
            } else 
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            if(dp[i+1][j] == dp[i+1][j+1]) 
                num[i+1][j+1] += num[i+1][j];
            if(dp[i][j+1] == dp[i+1][j+1]) 
                num[i+1][j+1] += num[i][j+1];
            if(dp[i+1][j+1] == dp[i][j]) 
                num[i+1][j+1] -= num[i][j];
        }
    }

    for(int i=0; i<=len1; i++) {
        for(int j=0; j<=len2; j++) {
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }

    printf("%d\n%d\n", dp[len1][len2], num[len1][len2]);
}

// ABCBDAB.
// BACBBD.

// 1 1 1 1 1 1 1 
// 1 1 1 1 1 1 1 
// 1 1 2 2 1 1 1 
// 1 1 2 2 3 3 3 
// 1 1 2 2 2 3 3 
// 1 1 2 2 2 3 3 
// 1 1 1 3 2 3 3 
// 1 1 1 3 3 2 5 

// 1 1 1 1 1 1 1 
// 1 1 1 1 1 1 1 
// 1 1 2 2 1 2 2 
// 1 1 2 2 3 4 4 
// 1 2 3 2 2 5 5 
// 1 2 3 2 2 5 5 
// 1 2 2 4 2 5 5 
// 1 3 2 4 6 2 7
