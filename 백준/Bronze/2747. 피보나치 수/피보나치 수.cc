#include<iostream>
#define MAX 50
using namespace std;

typedef long long ll;
ll dp[MAX];
int N;

void solve(){
    dp[0] = 0;
    dp[1] = 1;
    
    for (int n=2; n<=N; n++){
        dp[n] = dp[n-1] + dp[n-2];
    }
    cout << dp[N];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    solve();
}
