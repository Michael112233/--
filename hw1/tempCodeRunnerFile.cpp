#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int a[20000];

int main() {
    int x, cnt=0;
    scanf("%d%d", &n, &m);
    while(n!=0 && m!=0) {
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        printf("CASE# %d:\n", ++cnt);
        for(int j=0; j<m; j++) {
            scanf("%d", &x);
            int place = lower_bound(a, a+n, x) - a;
            if(a[place] == x)
                printf("%d found in %d\n", x, place+1);
            else
                printf("%d not found\n", x);
        }
        scanf("%d%d", &n, &m);
    }
}

// 4 1 
// 2
// 3
// 5
// 1
// 5 
// 5 2 
// 1
// 3
// 3
// 3
// 1
// 2
// 3 
// 0 0