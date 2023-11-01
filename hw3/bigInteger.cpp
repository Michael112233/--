#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

long long power(long long m, long long k) {
    long long sum=1;
    while(k > 0) {
        if(k&1)
            sum *= m;
        m = m*m;
        k >>= 1;
    }
    return sum;
}

int main() {
    long long l, r, k;
    while(cin >> l >> r >> k) {
        long long sum = 1;
        bool check=false;
        while(true) {
            if(l <= sum && sum <= r) {
                cout << sum << " ";
                check = true;
            }
            if(sum > r/k)
                break;
            sum *= k;
        }
        if(!check)
            printf("-1");
        printf("\n");
    }
}

// 999999999999999999
// 1000000000000000000