#include<iostream>
#include<algorithm>
#define MAX 10
using namespace std;

int arr[MAX];
int ans[MAX];
int N, M;
void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
}

void dfs(int n){
    if(n == M){
        for(int j=0; j<M; j++) cout << ans[j] << " ";
        cout << "\n";
        return;
    }
    
    int prev = 0;
    for(int j=0; j<N; j++){
        if(prev == arr[j]) continue;
        prev = arr[j];
        ans[n] = arr[j];
        dfs(n+1);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0);
}
