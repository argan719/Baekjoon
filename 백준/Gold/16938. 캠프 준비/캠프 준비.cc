#include<iostream>
#include<algorithm>
#define MAX 16
using namespace std;

int min_val = 1e6;
int max_val = 1;
int N, L, R, X;
int arr[MAX];
int ans;

void input(){
    cin >> N >> L >> R >> X;
    for(int i=0; i<N; i++) cin >> arr[i];  // 문제의 난이도
}

void dfs(int n, int cnt, long long sum, int low, int high){
    // 가지치기 (난이도는 전부 양수이기 때문에 가능한것)
    if(sum > R) return;
    
    if(n == N){
        // 정답처리
        if(cnt < 2) return;
        if(sum < L || sum > R) return;
        if(abs(high - low) < X) return;
        ans++;
        return;
    }
    
    // 해당 문제를 채택하는 경우
    dfs(n+1, cnt+1, sum + arr[n], min(low, arr[n]), max(high, arr[n]));
    // 해당 문제를 채택 안하는 경우
    dfs(n+1, cnt, sum, low, high);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0, 0, min_val, max_val);
    cout << ans;
}