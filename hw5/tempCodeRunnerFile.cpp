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
        while(left < num.size() && num[left] < num[left+1]) {
            left++;
        }
        for(int j=left+1; j<=num.size(); j++) {
            num[j-1] = num[j];
        }
    }
    cout << num << endl;
}