#include<iostream>
#define MAX 10
using namespace std;

int N;
int arr[MAX];
int ans;
int v[MAX];

void input(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
}

void dfs(int n, int prev, int sum){
    if(n == N-1){
        if(ans < sum) ans = sum;
        return;
    }
    
    for(int j=0; j<N; j++){
        if(v[j]) continue;
        v[j] = 1;
        dfs(n+1, arr[j], sum + abs(prev-arr[j]));
        v[j] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    for(int i=0; i<N; i++){
        v[i] = 1;
        dfs(0, arr[i], 0);
        v[i] = 0;
    }
    cout << ans;
}