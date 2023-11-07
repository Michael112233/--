#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int n, m, p;
vector<int> father;

void init() {
    for(int i=0; i<=n; i++) 
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
    int x, y;
    scanf("%d%d%d", &n, &m, &p);
    init();
    // for(int i=0; i<father.size(); i++)
    //     printf("%d ", father[i]);
    // printf("\n");
    for(int i=0; i<m; i++) {
        scanf("%d%d", &x, &y);
        union_node(x, y);
    }
    for(int i=0; i<p; i++) {
        scanf("%d%d", &x, &y);
        if(judge(x, y)) 
            puts("Yes");
        else
            puts("No");
    }
}