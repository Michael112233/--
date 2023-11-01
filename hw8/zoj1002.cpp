#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

char map[10][10];
int n, ans=0;

int moveX(int x, int y) {
    if(x == n-1) 
        x=0;
    else 
        x++;
    return x;
}

int moveY(int x, int y) {
    if(x == n-1)
        y++;
    return y;
}

void dfs(int x, int y, int cnt, vector<vector<bool> > &check) {
    if(x == n-1 && y == n-1) {
        if(!check[x][y])
            cnt++;
        ans = max(ans, cnt);
        return;
    }
    if(check[x][y]) {
        dfs(moveX(x, y), moveY(x, y), cnt, check);
        return;
    }
    vector<vector<bool> > new_check = check;
    // printf("%d %d\n", x, y);
    dfs(moveX(x, y), moveY(x, y), cnt, check);

    int tmpx=x, tmpy=y;
    while(tmpx >= 0) {
        if(map[tmpx][tmpy] == 'X')
            break;
        new_check[tmpx][tmpy] = true;
        tmpx--;
    }
    tmpx=x, tmpy=y;
    while(tmpx <= n-1) {
        if(map[tmpx][tmpy] == 'X')
            break;
        new_check[tmpx][tmpy] = true;
        tmpx++;
    }
    tmpx=x, tmpy=y;
    while(tmpy >= 0) {
        if(map[tmpx][tmpy] == 'X')
            break;
        new_check[tmpx][tmpy] = true;
        tmpy--;
    }
    tmpx=x, tmpy=y;
    while(tmpy <= n-1) {
        if(map[tmpx][tmpy] == 'X')
            break;
        new_check[tmpx][tmpy] = true;
        tmpy++;
    }
    dfs(moveX(x, y), moveY(x, y), cnt+1, new_check);
}

int main() {
    while(scanf("%d", &n) && n!=0) {
        ans = 0;
        vector<vector<bool> > check;
        vector<bool> tmp;
        for(int i=0; i<n; i++) 
            tmp.push_back(false);
        for(int i=0; i<n; i++) 
            check.push_back(tmp);

        for(int i=0; i<n; i++) {
            scanf("%s", map[i]);
            for(int j=0; j<n; j++) {
                if(map[i][j] == 'X')
                    check[i][j] = true;
            }
        }
        dfs(0, 0, 0, check);

        printf("%d\n", ans);
    }
}