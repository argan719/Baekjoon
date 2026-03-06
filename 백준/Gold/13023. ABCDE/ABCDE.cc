#include<iostream>
#include<vector>
//#include<cstdlib>
#define MAX 2001
using namespace std;
int N, M;
int a,b;
int v[MAX];

vector<int> adj[MAX];

void input(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        // 양방향 리스트
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void dfs(int n, int prev){
    if(n == 5){
        // 정답 처리
        cout << 1; exit(0);
    }
    
    for(int j : adj[prev]){
        if(v[j]) continue;
        v[j] = 1;
        dfs(n+1, j);
        v[j] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    for(int j=0; j<N; j++){
        v[j] = 1;
        dfs(1, j); // 0번 인덱스로 j번 사람을 택함.
        v[j] = 0;
    }
    cout << 0;
}