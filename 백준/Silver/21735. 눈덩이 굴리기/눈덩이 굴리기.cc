#include<iostream>
#define MAX 105
using namespace std;

int N, M;
int arr[MAX];
int ans;
void input(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
}

void dfs(int n, int m, int sum){
    //종료조건
    if(n == N || m == M){
        if(ans < sum) ans = sum;
        return;
    }
    
    // 해당 앞마당에서 1.굴리는 경우
    dfs(n+1, m+1, sum + arr[n+1]);
    // 해당 앞마당에서 2.던지는 경우
    dfs(n+2, m+1, (sum/2) + arr[n+2]);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0, 1);
    cout << ans;
}
