#include<cstdio>
#include<algorithm>

using namespace std;

void dfs(int pos, int n, int s[], int left, int right, int &sum) {
    if(pos == n) {
        int sol = max(left, right);
        // printf("%d %d\n", sum, sol);
        sum = min(sum, sol);
        return;
    }

    dfs(pos+1, n, s, left+s[pos], right, sum);
    dfs(pos+1, n, s, left, right+s[pos], sum);
}

int main() {
    int s1[30], s2[30], s3[30], s4[30];
    int s1_num, s2_num, s3_num, s4_num;
    scanf("%d%d%d%d", &s1_num, &s2_num, &s3_num, &s4_num);
    for(int i=0; i<s1_num; i++)
        scanf("%d", &s1[i]);
    for(int i=0; i<s2_num; i++)
        scanf("%d", &s2[i]);
    for(int i=0; i<s3_num; i++)
        scanf("%d", &s3[i]);
    for(int i=0; i<s4_num; i++)
        scanf("%d", &s4[i]);

    int sum=0x7ffffff, ans=0;
    dfs(0, s1_num, s1, 0, 0, sum);
    ans += sum;

    sum=0x7ffffff;
    dfs(0, s2_num, s2, 0, 0, sum);
    ans += sum;

    sum=0x7ffffff;
    dfs(0, s3_num, s3, 0, 0, sum);
    ans += sum;

    sum=0x7ffffff;
    dfs(0, s4_num, s4, 0, 0, sum);
    ans += sum;

    printf("%d\n", ans);
}