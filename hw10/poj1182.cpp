#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int n, k;
vector<int> father;

void init() {
    for(int i=0; i<=3*n; i++) 
        father.push_back(i);
}

int getFather(int x) {
    while(father[x] != x) 
        x = father[x];
    return x;
}

void union_node(int x, int y) {
    int father_x = getFather(x), father_y = getFather(y);
    if(father_x == father_y)
        return;
    father[father_y] = father_x;
}

bool judge(int x, int y) {
    int father_x = getFather(x), father_y = getFather(y);
    // printf("%d %d\n", x, father_x);
    // printf("%d %d\n", y, father_y);
    return father_x == father_y;
}

int main() {
    int cnt = 0, op, x, y;
    scanf("%d%d", &n, &k);
    init();
    for(int i=0; i<k; i++) {
        scanf("%d%d%d", &op, &x, &y);
        if(x>n || y>n) {
            cnt++;
            continue;
        }
        if(op == 1) {
            if(getFather(x) == getFather(y+n) || getFather(x) == getFather(y+2*n)) {
                cnt++;
                continue;
            }
            union_node(x, y);
            union_node(x+n, y+n);
            union_node(x+2*n, y+2*n);
        } else {
            if(x == y) {
                cnt++;
                continue;
            }
            if(getFather(x) == getFather(y+2*n) || getFather(x) == getFather(y)) {
                cnt++;
                continue;
            }
            union_node(x, y+n);
            union_node(x+n, y+2*n);
            union_node(x+2*n, y);
        }
    }
    printf("%d\n", cnt);
}

// 1-n 
// n+1-2n eat
// 2n+1-3n eaten