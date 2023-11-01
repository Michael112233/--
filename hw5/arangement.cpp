#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct program {
    int start, end;
}list[1001000];

bool cmp(program a, program b) {
    return (a.end == b.end) ? (a.start < b.start) : (a.end < b.end);
}

int main() {
    int n;
    scanf("%d", &n);
    // while(scanf("%d", &n) && n!=0) {
    for(int i=0; i<n; i++) {
        scanf("%d%d", &list[i].start, &list[i].end);
    }
    sort(list, list+n, cmp);
    int ans=0, last_end=0;

    for(int i=0; i<n; i++) {
        if(last_end <= list[i].start) {
            ans++;
            last_end = list[i].end;
        }
    }
    printf("%d\n", ans);
    // }
}