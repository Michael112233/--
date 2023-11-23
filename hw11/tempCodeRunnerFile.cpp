#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int a[100010];
int tree[500010];

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
    if(L == R) {
        if(l <= L && R <= r) 
            tree[pos] += x;
        return;
    }

    int mid = (L+R)/2;
    if(l <= mid)
        add(L, mid, l, mid, x, pos*2);
    if(mid+1 <= r) 
        add(mid+1, R, mid+1, r, x, pos*2+1);
    tree[pos] = tree[pos*2] + tree[pos*2+1];
}

int getSum(int L, int R, int l, int r, int pos) {
    if(L == R) {
        if(l <= L && R <= r) 
            return tree[pos];
        return 0;
    }

    int sum = 0;
    int mid = (L+R)/2;
    if(l <= mid)
        sum += getSum(L, mid, l, mid, pos*2);
    if(mid+1 <= r) 
        sum += getSum(mid+1, R, mid+1, r, pos*2+1);
    return sum;
}

int main() {
    int n, m;

    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) 
        scanf("%d", &a[i]);

    build(1, n, 1);

    int op, l, r, x;
    for(int i=1; i<=m; i++) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d%d%d", &l, &r, &x);
            add(1, n, l, r, x, 1);
        }
        if(op == 2) {
            scanf("%d%d", &l, &r);
            printf("%d\n", getSum(1, n, l, r, 1));
        }
    }
}