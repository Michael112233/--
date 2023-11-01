#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<string> ans;

string addNum(string s1, string s2) {
    int len1 = s1.size();
    int len2 = s2.size();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    if(len2 > len1)
        swap(s1, s2);
    int p = 0, k;
    string sum="";
    for(int i=0; i<len1; i++) {
        int a = s1[i] - '0';
        int b = 0;
        if(i < len2)
            b = s2[i] - '0';
        // printf("%d %d %d ", a, b, p);
        k = (a+b+p)%10;
        p = (a+b+p)/10;
        // printf("%d\n", k);
        sum += k+'0';
    }
    if(p == 1)
        sum += '1';
    reverse(sum.begin(), sum.end());
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    ans.push_back("1");
    ans.push_back("1");
    for(int i=2; i<=n; i++) {
        string sum = addNum(ans[i-1], ans[i-2]);
        ans.push_back(sum);
    }
    // for(int i=0; i<n; i++)
    cout << ans[n] << endl;
}