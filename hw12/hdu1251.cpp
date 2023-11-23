// example: hdu1251

#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

struct treeNode {
    char ch;
    int childNum;
    int visited;
    treeNode* children[30];
};

void add(treeNode* root, string str, int pos) {
    if(pos == str.size())
        return;
    // printf("%c %d %d\n", str[pos], root->childNum, root->visited);
    int i;
    bool find = false;
    for(i=0; i<root->childNum; i++) {
        if(root->children[i]->ch == str[pos]) {
            root->children[i]->visited ++;
            find = true;
            break;
        }
    }
    if(!find) {
        root->children[root->childNum] = (treeNode*)malloc(sizeof(treeNode));
        root->children[root->childNum]->ch = str[pos];
        root->children[root->childNum]->childNum = 0;
        root->children[root->childNum]->visited = 1;
        i = root->childNum;
        root->childNum++;
    }
    add(root->children[i], str, pos+1);
}

int query(treeNode* root, string str, int pos) {
    if(pos == str.size())
        return root->visited;
    bool find = false;
    int i;
    for(i=0; i<root->childNum; i++) {
        if(root->children[i]->ch == str[pos]) {
            find = true;
            break;
        }
    }
    if(!find) 
        return 0;
    return query(root->children[i], str, pos+1);
}

int main() {
    bool ask = false;
    string str;
    treeNode* root = (treeNode*)malloc(sizeof(treeNode));
    root->visited = 0;
    while(getline(cin, str)) {
        if(str == "") {
            ask = true;
            continue;
        }

        if(ask) {
            printf("%d\n", query(root, str, 0));
        } else {
            add(root, str, 0);
            // cout << str << endl;
        }
    }
}