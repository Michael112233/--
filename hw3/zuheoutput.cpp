#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iomanip>
#include<iostream>

using namespace std;

int main() {
    int n, r;
    vector<vector<int> > ans;
    scanf("%d%d", &n, &r);
    for(int i=0; i<(1<<n); i++) {
        int cnt=0;
        for(int j=0; j<n; j++) {
            if(i & (1<<j))
                cnt++;
        }
        // printf("%d\n", cnt);
        vector<int> tmp;
        int tmp_i = i;
        int cnt1 = n;
        if(cnt == r) {
            while(cnt1 > 0) {
                if(tmp_i % 2)
                    tmp.push_back(cnt1);
                tmp_i /= 2;
                cnt1--;
            }
            reverse(tmp.begin(), tmp.end());
        }
        if(tmp.size())
            ans.push_back(tmp);
    }
    reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++){
            cout << setw(3) << ans[i][j];
        }
        cout << endl;
    }
}