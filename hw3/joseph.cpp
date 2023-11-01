#include<cstdio>

int ans[14] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};

int main() {
    int k;
    scanf("%d", &k);
    while(k!=0) {
        printf("%d\n", ans[k]);
        scanf("%d", &k);
    }
}