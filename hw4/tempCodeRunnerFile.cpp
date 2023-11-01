#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int getAns(string &str,int l, int r, char target) {
    if(l == r) {
        if(str[l] == target)
            return 0;
        else
            return 1;
    }
    int sum1=0, sum2=0, mid = (l+r) >> 1;
    for(int i=l; i<=mid; i++) {
        if(str[i] != target)
            sum1++;
    }
    for(int i=mid+1; i<=r; i++) {
        if(str[i] != target)
            sum2++;
    }
    // cout << str1 << " " << str2 << endl;
    return min(sum1+getAns(str, mid+1, r, target+1), sum2+getAns(str, l, mid, target+1));
}

int main() {
    int T, n;
    string str;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        cin >> str;
        printf("%d\n", getAns(str, 0, n-1, 'a'));
    }
}