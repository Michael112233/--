#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;

map<int, int> temple; // first -> power; second -> id;

int main() {
    int n, x, y;
    scanf("%d", &n);
    while(n != 0) {
        temple.clear();
        temple[1e9] = 1;
        for(int i=0; i<n; i++) {
            int ans;
            scanf("%d%d", &x, &y);
            temple[y] = x;
            map<int, int>::iterator it = temple.find(y);
            if(it == temple.begin())
                ans = (++it)->second;
            else {
                map<int, int>::iterator it_left = --it;
                map<int, int>::iterator it_right = ++(++it);

                if(abs(it_left->first - y) <= abs(it_right->first - y))
                    ans = it_left->second;
                else
                    ans = it_right->second;
            }
            printf("%d %d\n", x, ans);
        }
        scanf("%d", &n);
    }
}