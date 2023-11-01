#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;

int n, m, t;
char map[25][25];
bool visited[25][25][1<<12];
int dx[5] = {1, -1, 0, 0};
int dy[5] = {0, 0, 1, -1};
struct Node {
    int x, y;
    int key;
    int time;
    Node(int x_, int y_, int key_, int time_) {
        x = x_;
        y = y_;
        key = key_;
        time = time_;
    }
};
queue<Node> q;

bool legal(int x, int y) {
    if(0<=x && x<n && 0<=y && y<m && map[x][y] != '*') {
        return true;
    }
    return false;
}

int bfs(int x, int y) {
    q.push(Node(x, y, 0, 0));
    visited[x][y][0] = true;

    while(!q.empty()) {
        Node current = q.front();
        q.pop();
        if(current.time >= t)
            return -1;
        if(map[current.x][current.y] == '^') 
            return current.time;
        for(int i=0; i<4; i++) {
            int next_x = current.x+dx[i];
            int next_y = current.y+dy[i];
            
            int key = 0;
            if(legal(next_x, next_y) && !visited[next_x][next_y][current.key]) {
                if(map[next_x][next_y] >= 'a' && map[next_x][next_y] <= 'j') {
                    key |= (1<<(map[next_x][next_y]-'a'));
                } else {
                    if(map[next_x][next_y] >= 'A' && map[next_x][next_y] <= 'J') {
                        if(!(current.key & (1<<(map[next_x][next_y]-'A'))))
                            continue;
                    }
                }
                q.push(Node(next_x, next_y, current.key|key, current.time+1));
                visited[next_x][next_y][current.key] = true;
            }
        }
    }
    return -1;
}

int main() {
    int posx, posy;
    while(cin >> n >> m >> t) {
        while(!q.empty()) {
            q.pop();
        }
        memset(visited, false, sizeof(visited));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> map[i][j];
                if(map[i][j] == '@') {
                    posx = i;
                    posy = j;
                }
            }
        }
        printf("%d\n", bfs(posx, posy));
    }
}