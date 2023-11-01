#include<set>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstdio>

using namespace std;

const int mod = 1e9+7;
const int base = 51089;

long long getHash(string str) {
    long long hash_val = 0;
    for(int i=0; i<str.size(); i++) {
        hash_val = ((hash_val * base) % mod + (int)str[i]) % mod;
    }
    return hash_val;
}

int main() {
    set<long long> hash;
    int n; 
    string str;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        cin>>str;
        hash.insert(getHash(str));
    }
    cout << hash.size() << endl;
}