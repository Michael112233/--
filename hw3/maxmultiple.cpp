#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

long long max(long long a, long long b) {
    return (a>b)?a:b;
}

int main() {
    int caseNum = 0, n;
    while(cin >> n) {
        caseNum++;
        vector<int> num;
        int x;
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            num.push_back(x);
        }
        long long maxn = 0;
        for(int i=0; i<n; i++) {
            int tmp = num[i];
            maxn = max(tmp, maxn);
            for(int j=i+1; j<n; j++) {
                tmp *= num[j];
                maxn = max(tmp, maxn);
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", caseNum, maxn);
    }
}