#include<cstdio>
#include<algorithm>
#include<cstring>

int chessboard[2000][2000];
int num=0;

void getAns(int c, int r, int x, int y, int size) {
    if(size == 1)
        return;
    int s = size/2;
    int tag = ++num;
    int mid_x = c+s-1;
    int mid_y = r+s-1;
    //left down
    if(x<=mid_x && y<=mid_y) { 
        getAns(c, r, x, y, s);
    } else {
        chessboard[mid_x][mid_y] = tag;
        getAns(c, r, mid_x, mid_y, s);
    }


    //left up
    if(x<=mid_x && y>mid_y) { 
        getAns(c, r+s, x, y, s);
    } else {
        chessboard[mid_x][mid_y+1] = tag;
        getAns(c, mid_y+1, mid_x, mid_y+1, s);
    }

    //right down
    if(x>mid_x && y<=mid_y) { 
        getAns(mid_x+1, r, x, y, s);
    } else {
        chessboard[mid_x+1][mid_y] = tag;
        getAns(mid_x+1, r, mid_x+1, mid_y, s);
    }

    //right up
    if(x>mid_x && y>mid_y) { 
        getAns(mid_x+1, mid_y+1, x, y, s);
    } else {
        chessboard[mid_x+1][mid_y+1] = tag;
        getAns(mid_x+1, mid_y+1, mid_x+1, mid_y+1, s);
    }

    
}

int main() {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    chessboard[x][y] = 0;
    getAns(1, 1, x, y, (1<<n));
    for(int i=1; i<=(1<<n); i++) {
        for(int j=1; j<=(1<<n); j++) {
            printf("%d ", chessboard[i][j]);
        }
        printf("\n");
    }
}