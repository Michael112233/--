#include<cstdio>
#include<queue>
#include<string>
#include<iostream>
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
    int lastPath;
    char move;
}path[362900];

queue<Node> q;

int dx[5] = {1, -1, 0, 0};
int dy[5] = {0, 0, 1, -1};
string moveStr = "udlr";

int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
bool visited[362900];

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
    int thisCantor = getCantor(state);
    q.push(Node(state, thisCantor, xPos));
    
    visited[thisCantor] = true;
    path[thisCantor].lastPath = -1;

    while(!q.empty()) {
        Node top = q.front();
        q.pop();
        int x = top.pos/3;
        int y = top.pos%3;
        for(int i=0; i<4; i++) {
            int cx = x+dx[i];
            int cy = y+dy[i];
            int cPos = cx*3+cy;
            if(!legal(cx, cy))
                continue;
            string cState = top.state;
            swap(cState[top.pos], cState[cPos]);
            int cCantor = getCantor(cState);
            if(visited[cCantor])
                continue;
            visited[cCantor] = true;
            q.push(Node(cState, cCantor, cPos));
            path[cCantor].lastPath = top.cantor;
            path[cCantor].move = moveStr[i];
        }
    }
}

int main() {
    string tmp;
    // printf("%d\n", getCantor("1234567x8"));
    bfs("12345678x", 8);
    while(getline(cin, tmp)) {
        string state;
        for(int i=0; i<tmp.size(); i++) 
            if(tmp[i] != ' ')
                state.push_back(tmp[i]);
        int cantor = getCantor(state);
        if(visited[cantor] == false) {
            printf("unsolvable\n");
        } else {
            while(true) {
                if(path[cantor].lastPath == -1)
                    break;
                printf("%c", path[cantor].move);
                cantor = path[cantor].lastPath;
            }
            printf("\n");
        }
    }
}


//123
//456
//78x