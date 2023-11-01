#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>

using namespace std;

char map[30][30];
bool visited[30][30];

bool check(int x, int y, int h, int w) {
    if(!(0<=x && x<h && 0<=y && y<w))
        return false;
    if(visited[x][y] || map[x][y] != '.')
        return false;
    return true;
}

int main() {
    // freopen("1.in", "r", stdin);
    int w, h;
    while(scanf("%d%d", &w, &h) && !(w==0 && h==0)) {
        getchar();
        int posx, posy;
        memset(visited, false, sizeof(visited));
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                scanf("%c", &map[i][j]);
                if(map[i][j] == '@') {
                    posx = i;
                    posy = j;
                    visited[i][j] = true;
                }
            }
            getchar();
        }

        // printf("\n");
        // for(int i=0; i<h; i++) {
        //     for(int j=0; j<w; j++) {
        //         printf("%c", map[i][j]);
        //     }
        //     printf("\n");
        // }
        queue<pair<int, int> > q;
        q.push(make_pair(posx, posy));
        while(!q.empty()) {
            pair<int, int> point = q.front();
            q.pop();
            int x=point.first, y=point.second;
            if(check(x-1, y, h, w)) {
                q.push(make_pair(x-1, y));
                visited[x-1][y] = true;
            }
            if(check(x+1, y, h, w)) {
                q.push(make_pair(x+1, y));
                visited[x+1][y] = true;
            }
            if(check(x, y-1, h, w)) {
                q.push(make_pair(x, y-1));
                visited[x][y-1] = true;
            }
            if(check(x, y+1, h, w)) {
                q.push(make_pair(x, y+1));
                visited[x][y+1] = true;
            }
        }

        int ans = 0;
        for(int i=0; i<h; i++) 
            for(int j=0; j<w; j++) 
                if(visited[i][j])
                    ans++;
        printf("%d\n", ans);
    }
}