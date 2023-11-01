#include<cstdio>
#include<vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    int sum=0;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    int avg = sum/n;
    for(int i=0; i<n; i++) {
        arr[i] -= avg;
    }
    int left = 0, right = n-1;
    while(left < n && arr[left] == 0)
        left++;
    while(right >= 0 && arr[right] == 0)
        right--;
    int ans=0;
    while(left <= right){
        arr[left+1] += arr[left];
        arr[left] = 0;
        ans++;
        left++;
        while(left <= right && arr[left] == 0)
            left++;
    }
    printf("%d\n", ans);
}