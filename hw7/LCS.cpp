#include<string>
#include<cstdio>
#include<iostream>

using namespace std;

string s1, s2;
int dp[1001][1001];

void init() {
    if(s1[0] == s2[0])
        dp[0][0] = 1;
    else
        dp[0][0] = 0;
    for(int i=1; i<s1.size(); i++)
        if(s1[i] == s2[0])
            dp[i][0] = 1;
        else
            dp[i][0] = dp[i-1][0];
    for(int i=1; i<s2.size(); i++)
        if(s1[0] == s2[i])
            dp[0][i] = 1;
        else
            dp[0][i] = dp[0][i-1];
}

int main() {
    while(cin >> s1 >> s2) {
        init();
        int len1 = s1.size();
        int len2 = s2.size();
        for(int i=1; i<s1.size(); i++)
            for(int j=1; j<s2.size(); j++) {
                if(s1[i] != s2[j])
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                else
                    dp[i][j] = dp[i-1][j-1]+1;
            }
        printf("%d\n", dp[len1-1][len2-1]);
    }
    
}