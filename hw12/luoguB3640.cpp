#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<string> str_list;

int main() {
    string str;
    getline(cin, str);
    string storeStr = "";
    int pos = 0;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == ' ') {
            
            int len = storeStr.size();
            if(storeStr[0] >= '0' && storeStr[0] <= '9') 
                reverse(storeStr.begin(), storeStr.end());
            if(storeStr[0] >= 'a' && storeStr[0] <= 'z') {
                for(int j=0; j<len; j++) {
                    // cout << (char)(storeStr[j] - 'a' + 'A') << endl;
                    storeStr[j] = (char)(storeStr[j] - 'a' + 'A');
                }
            }
            else if(storeStr[0] >= 'A' && storeStr[0] <= 'Z') {
                for(int j=0; j<len; j++)
                    storeStr[j] = (char)(storeStr[j] - 'A' + 'a');
            }
            str_list.push_back(storeStr);
            storeStr = "";
            pos = i+1;
        } else {
            storeStr += str[i];
        }
    }
    if(storeStr.size() > 0) {
        int len = storeStr.size();
        if(storeStr[0] >= '0' && storeStr[0] <= '9') 
            reverse(storeStr.begin(), storeStr.end());
        if(storeStr[0] >= 'a' && storeStr[0] <= 'z') {
            for(int i=0; i<len; i++)
                storeStr[i] += 'A' - 'a';
        } else
        if(storeStr[0] >= 'A' && storeStr[0] <= 'Z') {
            for(int i=0; i<len; i++)
                storeStr[i] += 'a' - 'A';
        }
        str_list.push_back(storeStr);
    }
    for(int i=str_list.size()-1; i>0; i--)
        cout << str_list[i] << " ";
    cout << str_list[0] << endl;
}