#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

long long ans=0;

void mergeSort(int l, int r, vector<int> &a) {
    if(l >= r)
        return;
    int mid = (l+r) >> 1;
    mergeSort(l, mid, a);
    mergeSort(mid+1, r, a);
    vector<int> tmp;
    int tmpl = l, tmpr = mid+1;
    // printf("%d %d\n", l, r);
    while(tmpl <= mid && tmpr <= r) {
        if(a[tmpl] > a[tmpr]) {
            tmp.push_back(a[tmpr]);
            ans += mid-tmpl+1;
            tmpr++;
        } else {
            tmp.push_back(a[tmpl]);
            tmpl++;
        }
    }
    while(tmpl <= mid)
        tmp.push_back(a[tmpl++]);
    while(tmpr <= r)
        tmp.push_back(a[tmpr++]);
    for(int i=l; i<=r; i++) {
        a[i] = tmp[i-l];
    }
}

vector<int> a;

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    mergeSort(0, n-1, a);
    printf("%lld\n", ans);
}