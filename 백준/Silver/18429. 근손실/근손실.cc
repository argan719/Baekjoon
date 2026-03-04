#include<iostream>
#define MAX 10
using namespace std;

int N, K;
int kit[MAX]; // 운동 키트 - 중량 증가량
int ans;
int v[MAX];

void input(){
    cin >> N >> K; // 0일차 ~ N-1일차
    for(int i=0; i<N; i++){
        cin >> kit[i];
    }
}
void dfs(int n, int sum){
    if(n == N){
        // 정답처리
        ans++;
        return;
    }
    
    for(int j=0; j<N; j++){
        if(v[j]) continue;
        if(sum + kit[j] - K < 500) continue;
        
        v[j] = 1;
        dfs(n+1, sum + kit[j] - K);
        v[j] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 500); // 초기 중량 500부터 시작.
    cout << ans;
}