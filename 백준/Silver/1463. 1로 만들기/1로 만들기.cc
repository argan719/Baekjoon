#include<iostream>
#define MAX (int)(1e6 + 1)
using namespace std;

int N;
int dp[MAX];


void solve(){
    dp[1] = 0;
    
    for(int i=2; i<=N; i++){
        dp[i] = dp[i-1] + 1;
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2]+1);
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3]+1);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    solve();
    cout << dp[N];
}