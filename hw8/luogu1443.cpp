#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int x_direct[10] = {-2, -1, 1, 2, 2, 1, -1, -2};
int y_direct[10] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m, x, y;

struct Point {
    int x, y, depth;
    
    Point(int x_, int y_, int depth_) {
        x = x_;
        y = y_;
        depth = depth_;
    }
};

int ans[500][500]; 

bool check(int x, int y) {
    if(!(1<=x && x<=n && 1<=y && y<=m)) 
        return false;
    if(ans[x][y] != -1)
        return false;
    return true;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    queue<Point> q;
    memset(ans, -1, sizeof(ans));
    ans[x][y] = 0;  

    q.push(Point(x, y, 0));

    while(!q.empty()) {
        Point top = q.front();
        q.pop();

        for(int i=0; i<8; i++) {
            if(check(top.x+x_direct[i], top.y+y_direct[i])) {
                ans[top.x+x_direct[i]][top.y+y_direct[i]] = top.depth+1;
                q.push(Point(top.x+x_direct[i], top.y+y_direct[i], top.depth+1));
            }
        }
        // for(int i=1; i<=n; i++) {
        //     for(int j=1; j<=m-1; j++)
        //         printf("%d ", ans[i][j]);
        //     printf("%d\n", ans[i][m]);
        // }
        // printf("%d %d %d\n", top.x, top.y, top.depth);
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m-1; j++)
            printf("%d ", ans[i][j]);
        printf("%d\n", ans[i][m]);
    }
}