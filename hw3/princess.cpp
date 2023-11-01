#include<algorithm>
#include<cstdio>
#include<iostream>

using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        int num[1000];
        for(int i=0; i<n; i++) 
            num[i] = i+1;
        for(int i=0; i<m-1; i++) {
            bool check = next_permutation(num, num+n);
        }
        for(int i=0; i<n-1; i++) {
            printf("%d ", num[i]);
        }
        printf("%d\n", num[n-1]);
    }
}