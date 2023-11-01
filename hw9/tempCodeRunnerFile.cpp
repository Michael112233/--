#include<cstdio>
#include<queue>
#include<string>
#include<stack>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

struct Node {
    string state;
    int cantor;
    int pos;

    Node(string state_, int cantor_, int pos_) {
        state = state_;
        cantor = cantor_;
        pos = pos_;
    }
};

struct Path {
    string state;
    int lastPath;
    char move;
}path[362900];

queue<Node> qfront;
queue<Node> qback;

int dx[5] = {1, -1, 0, 0};
int dy[5] = {0, 0, 1, -1};
string moveStr2 = "udlr";
string moveStr1 = "durl";
string midState1, midState2;
string ans;
bool check;

int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
bool visited1[362900];
bool visited2[362900];

int getCantor(string str) {
    int sum = 0;
    for(int i=0; i<str.size(); i++) {
        int cnt = 0;
        for(int j=i+1; j<str.size(); j++) {
            if(str[i] > str[j])
                cnt++;
        }
        sum += cnt * fac[str.size()-i-1];
    }
    return sum;
} 

bool legal(int x, int y) {
    if(0<=x && x<=2 && 0<=y && y<=2)
        return true;
    return false;
}

void bfs(string state, int xPos) {
    int thisCantor1 = getCantor(state);
    qback.push(Node(state, thisCantor1, xPos));
    int thisCantor2 = getCantor("12345678x");
    qfront.push(Node("12345678x", thisCantor2, 8));

    visited2[thisCantor1] = true;  // back
    path[thisCantor2].lastPath = -1;
    check = false;
    visited1[thisCantor2] = true; // front
    path[thisCantor1].lastPath = -1;

    int flag = 0; // flag=0 front, else back;
    int cnt = 0;
    while(!qfront.empty() || !qback.empty()) {
        if(cnt >= 362878) {
            check = true;
            return;
        }
        // printf("%d\n", cnt);
        // printf("%d %d\n", qfront.size(), qback.size());
        Node top("", 0, 0);
        if(qfront.empty()) {
            top = qback.front();
            qback.pop();
            flag = 1;
        } else if(qback.empty()){
            top = qfront.front();
            qfront.pop();
            flag = 0;
        } else {
            if(qfront.size() < qback.size()) {
                top = qfront.front();
                qfront.pop();
                flag = 0;
            } else {
                top = qback.front();
                qback.pop();
                flag = 1;
            }
        }
        
        // cout << top.state << endl;
        int x = top.pos/3;
        int y = top.pos%3;
        // if(visited1[top.cantor] && visited2[top.cantor]) {
        //     midState1 = midState2 = top.state;
        //     return;
        // }
        for(int i=0; i<4; i++) {
            int cx = x+dx[i];
            int cy = y+dy[i];
            int cPos = cx*3+cy;
            if(!legal(cx, cy))
                continue;
            string cState = top.state;
            swap(cState[top.pos], cState[cPos]);
            int cCantor = getCantor(cState);
            if((flag==0 && visited2[cCantor])) {
                midState2 = cState;
                midState1 = top.state;
                ans = moveStr1[i];
                return;
            }
            if((flag==1 && visited1[cCantor])) {
                midState1 = cState;
                midState2 = top.state;
                ans = moveStr2[i];
                return;
            }
            if((flag==0 && visited1[cCantor]) || (flag==1 && visited2[cCantor]))
                continue;
            if(!flag) {
                visited1[cCantor] = true;
                qfront.push(Node(cState, cCantor, cPos));
            } else {
                visited2[cCantor] = true;
                qback.push(Node(cState, cCantor, cPos));
            }
            path[cCantor].lastPath = top.cantor;
            // cout << path[cCantor].lastPath << endl;
            path[cCantor].move = (flag==0 ? moveStr1[i] : moveStr2[i]);
            path[cCantor].state = top.state;
            cnt++;
        }
    }
}

int main() {
    string tmp;
    while(getline(cin, tmp)) {
        while(!qfront.empty())
            qfront.pop();
        while(!qback.empty())
            qback.pop();
        string state = "";
        memset(visited1, false, sizeof(visited1));
        memset(visited2, false, sizeof(visited2));
        int pos=0;
        for(int i=0; i<tmp.size(); i++) 
            if(tmp[i] != ' ') {
                state += tmp[i];
                if(tmp[i] == 'x')
                    pos = state.size()-1;
            }
        bfs(state, pos);
        if(check) {
            puts("unsolvable");
            continue;
        }
        int cantor1 = getCantor(midState1);
        int cantor2 = getCantor(midState2);
        while(true) {
            if(path[cantor1].lastPath == -1) 
                break;
            ans = path[cantor1].move + ans;
            cantor1 = path[cantor1].lastPath;
        }
        while(true) {
            if(path[cantor2].lastPath == -1) 
                break;
            ans = ans + path[cantor2].move;
            cantor2 = path[cantor2].lastPath;
        }
        cout << ans << endl;
    }
}

