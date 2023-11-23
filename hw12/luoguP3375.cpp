#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<string>

using namespace std;

vector<int> nextArray;

void get_next(string s2) {
    int k=0;
    nextArray.push_back(0);
    for(int i=1; i<s2.size(); i++) {
        while(k>0 && s2[i] != s2[k])
            k = nextArray[k-1];
        if(s2[i] == s2[k])
            k++;
        nextArray.push_back(k);
    }
}

void find(string s1, string s2) {
    int i = 0;
    int currentPos;
    while(i < s1.size()) {
        if(s1[i] == s2[0]) {
            int j=1;
            for(; j<s2.size(); j++) {
                if(s1[i+j] != s2[j])
                    break;
            }
            if(j == s2.size())
                printf("%d\n", i+1);
            i += j-nextArray[j-1];
        } else {
            i++;
        }
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    get_next(s2);
    find(s1, s2);
    for(int i=0; i<nextArray.size(); i++)
        printf("%d ", nextArray[i]);
    printf("\n");
}