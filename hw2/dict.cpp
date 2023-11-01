#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<string>

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
    unordered_map<long long, string> firstHash;
    unordered_map<long long, string> secondHash;
    string str;
    while(getline(cin, str) && str != "@END@") {
        int pos = str.find(']');
        string str1 = str.substr(0, pos+1);
        string str2 = str.substr(pos+2, str.size()-1);
        string str3 = str.substr(1, pos-1);
        // cout << str1 << " " << str2 << endl;
        firstHash[getHash(str1)] = str2;
        secondHash[getHash(str2)] = str3;
    }
    int n;
    cin >> n;
    getchar();
    for(int i=0; i<n; i++) {
        getline(cin, str);
        if(str[0] == '[')
            if(firstHash.count(getHash(str)) > 0)
                cout << firstHash[getHash(str)] << endl;
            else
                cout << "what?" << endl;
        else
            if(secondHash.count(getHash(str)) > 0)
                cout << secondHash[getHash(str)] << endl;
            else
                cout << "what?" << endl;
    }
}