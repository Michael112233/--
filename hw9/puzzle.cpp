#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;

char map[45][45];
bool visited[45][45];
int n, m;
int dx[5] = {1, -1, 0, 0};
int dy[5] = {0, 0, 1, -1};
struct Node {
    int x, y;
    int move;
    Node(int x_, int y_, int move_) {
        x = x_;
        y = y_;
        move = move_;
    }
};
queue<Node> q;

bool legal(int x, int y) {
    if(0<=x && x<n && 0<=y && y<m && map[x][y] != '#') {
        return true;
    }
    return false;
}

int bfs(int x, int y) {
    q.push(Node(x, y, 1));
    while(!q.empty()) {
        Node top = q.front();
        q.pop();
        int x = top.x;
        int y = top.y;
        if(x==n-1 && y==m-1)
            return top.move;
        for(int i=0; i<4; i++) {
            int cx = x+dx[i];
            int cy = y+dy[i];
            if(legal(cx, cy) && !visited[cx][cy]) {
                // printf("%d %d %d\n", cx+1, cy+1, top.move+1);
                q.push(Node(cx, cy, top.move+1));
                visited[cx][cy] = true;
            }
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>map[i][j];
        }
    }
    printf("%d\n", bfs(0, 0));
}