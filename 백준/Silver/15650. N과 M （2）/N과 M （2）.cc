#include<iostream>
#define MAX 10
using namespace std;

int result[MAX];
int visited[MAX];

int N, M;
void dfs(int n, int cur){
    
    if(n >= M) {
        for(int i=0;i<M; i++){
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=cur+1; i<=N; i++){
        if(visited[i]) continue;
        visited[i] = 1;
        result[n] = i;
        dfs(n+1, i);
        visited[i] = 0;
    }
}

int main(void){
    cin >> N >> M;
    
    dfs(0, 0);
}