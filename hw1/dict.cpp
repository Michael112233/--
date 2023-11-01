#include<cstdio>
#include<set>
#include<vector>
#include<sstream>
#include<iostream>

using namespace std;

set<string> dict;

int main() {
    string s, wordstr;
    while(cin>>s) {
        string word = "";
        vector<string> word_list;
        for(int i=0; i<s.size(); i++) {
            if(isalpha(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i] = ' ';
        }
        
        stringstream str(s);
        while(str >> wordstr) {
            dict.insert(wordstr);
        }
    }
    
    for(string word : dict) {
        cout << word << endl;
    }
}