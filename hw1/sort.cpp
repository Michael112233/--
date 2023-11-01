#include<algorithm>
#include<cstdio>
#include<iostream>

using namespace std;

int n, m;
int a[1000010];

int main() {
    while(cin >> n >> m) {
        for(int i=0; i<n; i++) 
            scanf("%d", &a[i]);
        sort(a, a+n);
        reverse(a, a+n);
        for(int i=0; i<m-1; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[m-1]);
    }
}