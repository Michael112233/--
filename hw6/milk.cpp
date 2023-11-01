#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Cow {
    int start, finish, income, id;
};
Cow cow[1010];
int dp[1010];
int rec[1010] = {0};
int n, m, r;

bool cmp(Cow a, Cow b) {
    return (a.finish == b.finish) ? (a.start < b.start) : (a.finish < b.finish);
}

int find(int pos, int l, int r) {
    if(l == r) {
        if(cow[l].finish > cow[pos].start)
            return l-1;
        if(l == n && cow[l].finish < cow[pos].start)
            return 0;
        return l;
    }
    // printf("%d %d\n", l, r);
    int mid = (l+r)/2;
    if(cow[mid].finish > cow[pos].start)
        return find(pos, l, mid);
    else
        return find(pos, mid+1, r);
}

int main() {
    scanf("%d%d%d", &n, &m, &r);
    for(int i=1; i<=m; i++) {
        scanf("%d%d%d", &cow[i].start, &cow[i].finish, &cow[i].income);
        cow[i].finish = min(n, cow[i].finish + r);
        cow[i].id = i;
    }
    sort(cow+1, cow+m+1, cmp);

    // for(int i=1; i<=m; i++) {
    //     printf("%d %d %d\n", cow[i].start, cow[i].finish, cow[i].income);
    // }

    vector<int> p;
    p.push_back(0);
    for(int i=1; i<=m; i++) {
        p.push_back(find(i, 1, i));
    }
    
    // for(int i=0; i<p.size(); i++)
    //     printf("%d ", p[i]);

    dp[0] = 0;
    for(int i=1; i<=m; i++) {
        dp[i] = max(dp[i-1], dp[p[i]] + cow[i].income);
        if(dp[i] != dp[i-1])
            rec[i] = 1;
    }
    printf("%d\n", dp[m]);

    // vector<int> ans;
    // int k = m-1;
    // while(k != 0) {
    //     printf("%d\n", k);
    //     if(rec[k]) {
    //         ans.push_back(cow[k].id);
    //         k = p[k];
    //     } else {
    //         k--;
    //     }
    // }
    // for(int i=0; i<ans.size(); i++) {
    //     printf("%d ", ans[i]);
    // }
    // printf("\n");
}