#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int map[5][5] = {{2, 3, 4}, {1, 5, 0}, {7, 6, 8}};
int dx[5] = {1, -1, 0, 0};
int dy[5] = {0, 0, 1, -1};

char action[100000];

int main() {
    int x = 1, y = 2, k;
    cin >> action;
    int newx, newy;
    for(int z=0; z<strlen(action); z++) {
        if(action[z] == 'd') 
            k=0;
        if(action[z] == 'u') 
            k=1;
        if(action[z] == 'r') 
            k=2;
        if(action[z] == 'l') 
            k=3;
        newx = x+dx[k];
        newy = y+dy[k];
        int t = map[x][y];
        map[x][y] = map[newx][newy];
        map[newx][newy] = t;
        // swap(map[x][y], map[newx][newy]);
        x = newx;
        y = newy;
        // printf("%d %d\n", x, y);
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
}