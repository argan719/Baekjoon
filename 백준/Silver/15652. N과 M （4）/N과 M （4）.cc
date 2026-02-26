#include<iostream>
#define MAX 10
using namespace std;

int N, M;
int ans[MAX];
void input(){
    cin >> N >> M;
}

void dfs(int n, int start){
    // 종료조건은 이곳에서
    if(n == M){
        for(int j=0; j<M; j++) cout << ans[j] << " ";
        cout << "\n";
        return;
    }
    
    for(int j=start; j<=N; j++){
        ans[n] = j;
        dfs(n+1, j);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 1);
}