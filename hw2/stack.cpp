#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int a[3000010];

int main() {
    stack<pair<int, int> > myStack;
    vector<int> ans;
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    for(int i=n; i>=1; i--) {
        while(!myStack.empty() && myStack.top().first<=a[i])
            myStack.pop();
        if(myStack.empty())
            ans.push_back(0);
        else
            ans.push_back(myStack.top().second);
        myStack.push(make_pair(a[i], i));
    }
    reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size()-1; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[ans.size()-1]);
}