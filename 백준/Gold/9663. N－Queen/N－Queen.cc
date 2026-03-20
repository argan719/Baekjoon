#include<iostream>
#define MAX 16
using namespace std;
int N;
int vRow[MAX];
int vLeft[2*MAX];
int vRight[2*MAX];
int ans;

void input(){
    cin >> N;
}

void dfs(int n){
    if(n == N){
        ans++;
        return;
    }
    
    for(int j=0; j<N; j++){
        if(vRow[j] || vRight[n+j] || vLeft[n-j + N]) continue;
        // 방문처리
        vRow[j] = 1;
        vRight[n + j] = 1;
        vLeft[n - j + N] = 1;
        
        dfs(n+1);
        
        vRow[j] = 0;
        vRight[n + j] = 0;
        vLeft[n - j + N] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0);
    cout << ans << "\n";
}
