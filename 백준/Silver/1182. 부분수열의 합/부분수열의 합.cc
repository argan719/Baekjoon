#include<iostream>
#define MAX 21
using namespace std;
int N, S;
int arr[MAX];
int cnt;

void input(){
    cin >> N >> S;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
}
void dfs(int n, int sum){
    // 종료조건은 이곳에서
    if(n >= N){
        // 정답처리
        if(sum == S) cnt++;
        return;
    }
    
    // 크기가 양수, 즉 크기가 1~N인 수열
    dfs(n+1, sum+arr[n+1]);
    dfs(n+1, sum);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    for(int j=1; j<=N; j++) dfs(j, arr[j]);
    cout << cnt;
}