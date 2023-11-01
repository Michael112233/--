#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b) {
    return a>b ? a : b;
}

int getSum(vector<int> &a, int l, int r, int &lget, int &rget) {
    if(r == l) {
        lget = l;
        rget = l;
        return a[l];
    }
    if(l > r)
        return 0;
    int mid = (l+r) >> 1;
    int l1, r1, l2, r2;
    int sum1 = getSum(a, l, mid, l1, r1);
    int sum2 = getSum(a, mid+1, r, l2, r2);
    int sum3=0, suml=0, sumr=0, maxl=-100000, maxr=-100000;
    int l3=mid, r3=mid+1;
    for(int i=mid; i>=l; i--) {
        suml += a[i];
        if(suml >= maxl) {
            maxl = suml;
            l3 = i;
        }
    }
    for(int i=mid+1; i<=r; i++) {
        sumr += a[i];
        if(sumr >= maxr) {
            maxr = sumr;
            r3 = i;
        }
    }
    // printf("%d %d %d %d %d %d\n", l1,r1, l2, r2, l3, r3);
    sum3 = maxl+maxr;
    int ans = 0;
    if(sum1>=sum2 && sum1>=sum3) {
        lget = l1;
        rget = r1;
        return sum1;
    }
    else {
        if(sum2>=sum1 && sum2>=sum3) {
            lget = l2;
            rget = r2;
            return sum2;
        } else {
            lget = l3;
            rget = r3;
            return sum3;
        }
    }
}

int main() {
    int n, x, T, cnt=0;
    bool print=true;
    scanf("%d", &T);
    while(T--) {
        if(!print) {
            printf("\n");
        } else {
            print = false;
        }
        vector<int> a;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            a.push_back(x);
        }
        int lans=0, rans=0;
        int ans=getSum(a, 0, n-1, lans, rans);
        printf("Case %d:\n", ++cnt);
        printf("%d %d %d\n", ans, lans+1, rans+1);
    }
}