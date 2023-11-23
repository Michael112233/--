#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int heap[100100];
int len=0;

void up(int pos) {
    int x = heap[pos];
    while(pos >= 2) {
        int upper = heap[pos/2];
        if(x < upper) {
            swap(heap[pos], heap[pos/2]);
            pos /= 2;
        } else {
            break;
        }
    }
}

void down(int pos) {
    int x = heap[pos];
    while(pos * 2 <= len) {
        int left = pos*2;
        if(left+1 <= len && heap[left+1] <= heap[left]) 
            left++;
        if(heap[pos] <= heap[left])
            break;
        swap(heap[pos], heap[left]);
        pos = left;
    } 
}

int main() {
    int n, x;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &x);
        heap[++len] = x;
        up(i);
    }
    for(int i=1; i<=n; i++) {
        printf("%d ", heap[1]);
        swap(heap[1], heap[len--]);
        down(1); 
    }
}