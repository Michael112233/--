#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct Node {
    int l, r;
}tree[100010];

void preorder(int root) {
    if(root == 0)
        return;
    printf("%d ", root);
    preorder(tree[root].l);
    preorder(tree[root].r);
}

void inorder(int root) {
    if(root == 0)
        return;
    inorder(tree[root].l);
    printf("%d ", root);
    inorder(tree[root].r);
}

void postorder(int root) {
    if(root == 0)
        return;
    postorder(tree[root].l);
    postorder(tree[root].r);
    printf("%d ", root);
}

int main() {
    int n;
    int l, r;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d%d", &l, &r);
        tree[i].l = l;
        tree[i].r = r;
    }
    preorder(1);
    printf("\n");
    inorder(1);
    printf("\n");
    postorder(1);
    printf("\n");
}