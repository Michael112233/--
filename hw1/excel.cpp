#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

struct Student {
    string number, name;
    int score;
};

int c;

bool cmp(Student a, Student b) {
    if(c==1) {
        return a.number<b.number;
    } else {
        if(c==2) {
            return (a.name == b.name) ? (a.number < b.number) : (a.name < b.name);
        } else {
            return (a.score == b.score) ? (a.number < b.number) : (a.score < b.score);
        }
    }
}

int main() {
    int cnt=0, n;
    scanf("%d%d", &n, &c);
    while(n!=0 && c!=0) {
        Student a[100010];
        for(int i=0; i<n; i++) {
            cin>>a[i].number>>a[i].name>>a[i].score;
        }
        sort(a, a+n, cmp);
        printf("Case %d:\n", ++cnt);
        for(int i=0; i<n; i++) {
            cout<<a[i].number<<" "<<a[i].name<<" "<<a[i].score<<endl;
        }
        scanf("%d%d", &n, &c);
    }
}