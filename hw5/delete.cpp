#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main() {
    string num;
    int k;
    cin >> num;
    scanf("%d", &k);
    for(int i=1; i<=k; i++) {
        int left = 0;
        while(left < num.size() && num[left] <= num[left+1]) {
            left++;
        }
        num.erase(left, 1);
    }
    while(num.size() > 1 && num[0]=='0')
        num.erase(0, 1);
    cout << num << endl;
}