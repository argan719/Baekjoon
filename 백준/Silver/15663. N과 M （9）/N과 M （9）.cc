#include<iostream>
#include<algorithm>
#define MAX 10
using namespace std;

int ans[MAX];
int arr[MAX];
int N, M;
int v[MAX];

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
}

void dfs(int n){
    // 종료조건은 여기에서
    if(n == M){
        for(int j=0; j<M; j++) cout << ans[j] << " ";
        cout << "\n";
        return;
    }
    
    // 하부함수 호출
    int prev = 0;
    for(int j=0; j<N; j++){
        if(v[j]) continue;
        if(prev == arr[j]) continue;
        v[j] = 1;
        prev = arr[j];
        ans[n] = arr[j];
        dfs(n+1);
        v[j] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0);
    
}