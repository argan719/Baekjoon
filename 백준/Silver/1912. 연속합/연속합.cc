#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;

long long arr[MAX];
long long dp[MAX];
int N;
long long ans;

void input(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
}

void solve(){
    ans = -1e4;
    for(int i=1; i<=N; i++){
        dp[i] = max(arr[i] + dp[i-1], arr[i]);
        ans = max(dp[i], ans);
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}