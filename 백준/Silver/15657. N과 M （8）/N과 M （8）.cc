#include<iostream>
#include<algorithm>
#define MAX 10
using namespace std;

int ans[MAX];
int arr[MAX];
int N, M;

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
}

void dfs(int n, int start){
    // 종료조건은 여기에서
    if(n == M){
        for(int j=0; j<M; j++) cout << ans[j] << " ";
        cout << "\n";
        return;
    }
    
    // 하부함수 호출
    for(int j=start; j<N; j++){
        ans[n] = arr[j];
        dfs(n+1, j);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0);
}