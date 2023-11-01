#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

bool legal(int a, int b) {
    int hash[15] = {0};
    for(int i=0; i<5; i++){
        hash[a%10] = 1;
        a /= 10;
    }
    for(int i=0; i<5; i++){
        hash[b%10] = 1;
        b /= 10;
    }
    for(int i=0; i<=9; i++)
        if(hash[i] == 0)
            return false;
    return true;
}

int main() {
    int n, cnt=0;
    bool presentation = false;
    while(cin>>n && n!=0) {
        if(!presentation)
            presentation = true;
        else
            printf("\n");
        bool check = false;
        for(int i=1234; n*i<=98765; i++) {
            if(legal(i, n*i)) {
                check = true;
                printf("%05d / %05d = %d\n", n*i, i, n);
            }
        }
        if(!check)
            printf("There are no solutions for %d.\n", n);
        cnt++;
    }
}