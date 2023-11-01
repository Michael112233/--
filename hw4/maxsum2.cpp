#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int getSum(vector<int> &a, int left, int right) {
    if(left > right)
        return 0;
    if(left == right)
        return a[left];
    int mid = (left + right) / 2;
    int sum1 = getSum(a, left, mid);
    int sum2 = getSum(a, mid+1, right);
    int ans = max(sum1, sum2);
    int suml=0, sumr=0, maxl=-10000000, maxr=-10000000;
    for(int i=mid; i>=left; i--) {
        suml += a[i];
        maxl = max(suml, maxl);
    }
    for(int i=mid+1; i<=right; i++) {
        sumr += a[i];
        maxr = max(maxr, sumr);
    }
    // printf("%d %d %d\n", left, right, max(ans, maxl+maxr));
    return max(ans, maxl+maxr);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a;
    a.resize(n*2);
    for(int i=0; i<n; i++) 
        scanf("%d", &a[i]);
    printf("%d\n", getSum(a, 0, n-1));
}