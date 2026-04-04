#include<iostream>
#include<algorithm>
#define MAX 1001
using namespace std;
int N;
int arr[MAX];
int dp[MAX];
int ans;

void input(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
}

void solve(){
    
    int ans_max = 0;
    int cnt_max;
    
    for(int i=1; i<=N; i++){
        cnt_max = 0;
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                cnt_max = max(cnt_max, dp[j]);
            }
        }
        dp[i] = cnt_max + 1;
        ans_max = max(ans_max, dp[i]);
    }
    cout << ans_max;
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}