#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define pair1 pair<int, int>

using namespace std;

struct program {
    int start, end, id;
}list[1001000];

bool cmp(program a, program b) {
    return a.start < b.start;
}

int main() {
    vector<vector<int> > cow;
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &list[i].start, &list[i].end);
        list[i].id = i;
    }
    sort(list, list+n, cmp);
    priority_queue<pair1, vector<pair1>, greater<pair1> > q;
    vector<int> ans(n);
    for(int i=0; i<n; i++) {
        if(q.empty() || q.top().first >= list[i].start) {
            pair1 p;
            p.first = list[i].end;
            p.second = q.size();
            ans[list[i].id] = q.size();
            q.push(p);
        } else {
            pair1 p = q.top();
            q.pop();
            p.first = list[i].end;
            ans[list[i].id] = p.second;
            q.push(p);
        }
    }
    printf("%d\n", q.size());
    for(int i=0; i<ans.size(); i++)
        printf("%d\n", ans[i]+1);
}