#include<iostream>
#define MAX 9
using namespace std;

int ans[MAX];
int v[MAX];
int N;

void dfs(int n){
    // 정답처리는 이곳에서
    if(n == N){
        for(int j=0; j<N; j++) cout << ans[j] << " ";
        cout << "\n";
        
        return;
    }
    
    // 하부 함수 호출
    for(int j=1; j<=N; j++){
        if(v[j]) continue;
        v[j] = 1;
        ans[n] = j;
        dfs(n+1);
        v[j] = 0;
    }
}

int main(){
    cin >> N;
    dfs(0);
}