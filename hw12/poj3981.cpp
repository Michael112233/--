#include<string>
#include<iostream>

using namespace std;

int main() {
    string str;
    while(getline(cin, str)) {
        int pos = str.find("you");
        while(pos != -1) {
            str.replace(pos, 3, "we");
            pos = str.find("you");
        }
        cout << str << endl;
    }
}