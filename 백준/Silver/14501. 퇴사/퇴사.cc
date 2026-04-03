#include<iostream>
#define MAX 16
using namespace std;

int arr[MAX][MAX]; // Ti Pi
int N;
int ans;

void input(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
}

void dfs(int n, int start, int sum){
    // 종료조건은 이곳에서
    if(n > N){
        // 정답처리
        if(ans < sum) ans = sum;
        return;
    }
    
    // 하부함수 호출
    if(start <= n && n + arr[n][0] <= N+1) dfs(n+1, n + arr[n][0], sum + arr[n][1]);
    dfs(n+1, start, sum);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(1, 0, 0);
    cout << ans;
}