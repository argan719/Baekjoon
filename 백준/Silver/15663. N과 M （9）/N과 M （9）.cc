#include<iostream>
#include<algorithm>
#define MAX 10001
using namespace std;

int N, M;
int arr[MAX];
int v[MAX];
int ans[MAX];

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
}

void dfs(int n){
    // 종료조건
    if(n == M){
        for(int i=0; i<M; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    
    int prev = -1;
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