#include<iostream>
#define MAX 10
using namespace std;

int N, M;
int arr[MAX];

void input(){
    cin >> N >> M;
}

void dfs(int n){
    // 종료조건은 여기에서
    if(n == M){
        // 정답 출력
        for(int j=0; j<M; j++) cout << arr[j] << " ";
        cout << "\n";
        return;
    }
    
    // 하부 함수 호출
    for(int j=1; j<=N; j++){
        arr[n] = j;
        dfs(n+1);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0);
}