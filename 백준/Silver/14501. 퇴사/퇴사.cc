#include<iostream>
#include<algorithm>
#define MAX 17
using namespace std;

int arr[MAX][MAX];
int dp[MAX];
int N;
int ans;

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i][0] >> arr[i][1];  // Ti, Pi
    }
}

void solve(){
    
    for(int n=N-1; n>=0; n--){
        if(n + arr[n][0] <= N) dp[n] = max(dp[n+1], dp[n + arr[n][0]] + arr[n][1]);
        else dp[n] = dp[n+1];
    }
    
    ans = dp[0];
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}
