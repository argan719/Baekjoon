#include<iostream>
#define MAX 9
using namespace std;

int N, M;
int v[MAX];
int ans[MAX];

void input(){
    cin >> N >> M;
}

void dfs(int n){
    // 정답처리부터 제일 먼저
    if(n == M){
        // 수열 바로 출력하기
        for(int i=0; i<M; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    
    for(int j=1; j<=N; j++){
        if(v[j]) continue;
        v[j] = 1;  // 방문처리
        ans[n] = j;  // n이 곧 인덱스가 되는 것. (덮어씌워짐)
        dfs(n+1);
        v[j] = 0;  // 방문처리 clear
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    dfs(0);
}