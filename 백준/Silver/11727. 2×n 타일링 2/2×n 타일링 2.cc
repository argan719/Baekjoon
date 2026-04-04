#include<iostream>
#define MAX 1005
using namespace std;

int N;
long long dp[MAX];

void solve(){
    // 초기값 설정.
    dp[1] = 1; dp[2] = 3;
    for(int i=3; i<=N; i++){
        dp[i] = (dp[i-1] + dp[i-2]*2)%10007;
    }
    cout << (int)(dp[N]%10007);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    solve();
}
