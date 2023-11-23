#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

long long a[100010];
long long tree[500010];

void build(int l, int r, int pos) {
    if(l == r) {
        tree[pos] = a[l];
        return;
    }

    int mid = (l+r)/2;
    build(l, mid, pos*2);
    build(mid+1, r, pos*2+1);
    tree[pos] = tree[pos*2] + tree[pos*2+1];
}

void add(int L, int R, int l, int r, int x, int pos) {
    if(l <= L && R <= r) {
        tree[pos] += x;
        return;
    }

    int mid = (L+R)/2;
    if(l <= mid) {
        add(L, mid, l, r, x, pos*2);
    }
    if(mid+1 <= r) {
        add(mid+1, R, l, r, x, pos*2+1);
    }
    tree[pos] = tree[pos*2] + tree[pos*2+1];
}

long long getSum(int L, int R, int l, int r, int pos) {
    if(l <= L && R <= r) 
        return tree[pos];

    long long sum = 0;
    int mid = (L+R)/2;
    if(l <= mid) {
        sum += getSum(L, mid, l, r, pos*2);
    }
    if(mid+1 <= r) {
        sum += getSum(mid+1, R, l, r, pos*2+1);
    }
    return sum;
}

int main() {
    int n, m;

    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) 
        scanf("%lld", &a[i]);

    build(1, n, 1);

    int op, l, r;
    long long x;
    for(int i=1; i<=m; i++) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d%d%lld", &l, &r, &x);
            add(1, n, l, r, x, 1);
        }
        if(op == 2) {
            scanf("%d%d", &l, &r);
            printf("%lld\n", getSum(1, n, l, r, 1));
        }
    }
}