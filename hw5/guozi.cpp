#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main() {
    int n, x, sum=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        q.push(x);
    }
    while(q.size() >= 2) {
        int top1 = q.top();
        q.pop();
        int top2 = q.top();
        q.pop();
        sum += top1+top2;
        q.push(top1+top2);
    }
    printf("%d\n", sum);
}
