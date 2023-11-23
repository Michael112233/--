#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

priority_queue<int> q_big;
priority_queue<int, vector<int>, greater<int> > q_small;

int main() {
    int n, x;
    scanf("%d", &n);
    scanf("%d", &x);
    q_big.push(x);
    printf("%d\n", q_big.top());
    if(n >= 2) {
        scanf("%d", &x);
        if(x > q_big.top()) 
            q_small.push(x);
        else {
            q_small.push(q_big.top());
            q_big.pop();
            q_big.push(x);
        }
    }
    for(int i=0; i<n-2; i++) {
        scanf("%d", &x);
        int big_top = q_big.top();
        int small_top = q_small.top();
        // printf("%d %d\n", q_big.size(), q_small.size());
        if(q_big.size() == q_small.size()) {
            if(x < small_top) 
                q_big.push(x);
            else {
                q_big.push(small_top);
                q_small.pop();
                q_small.push(x);
            }
        } else {
            if(x >= big_top) 
                q_small.push(x);
            else {
                q_small.push(big_top);
                q_big.pop();
                q_big.push(x);
            }
        }
        if(i%2 == 0)
            printf("%d\n", q_big.top());
    }
}