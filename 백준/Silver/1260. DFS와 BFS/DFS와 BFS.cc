// 1260 인접행렬 - 2차원 배열 대신 벡터 사용하는 코드로 리펙토링
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAX 1001

using namespace std;
int N, M, V;

vector<int> ans_bfs;
vector<int> ans_dfs;
vector<int> adj[MAX];  // 벡터 배열 선언

int visited[MAX];

void dfs(int n){
    visited[n] = 1;
    ans_dfs.push_back(n);
    
    // r,c의 범위는 1부터 N
    for(int cur : adj[n]){
        if(visited[cur]) continue;
        
        dfs(cur);
    }
}

void bfs(int v) {
    queue<int> q;
    
    // push 할 때 작업하기
    q.push(v);
    visited[v] = 1;
    ans_bfs.push_back(v);
    
    int cur;
    
    while(!q.empty()){
        cur = q.front();
        q.pop();
        
        for(int n : adj[cur]){
            if(visited[n]) continue;  // 범위내 미방문 조건 맞으면
            
            // push 할 때 작업하기
            q.push(n);
            visited[n] = 1;
            ans_bfs.push_back(n);
        }
    }
}

int main(){
    cin >> N >> M >> V;
    
    int r,c;
    for(int i=0; i<M; i++){
        cin >> r >> c;
        adj[r].push_back(c);
        adj[c].push_back(r);
    }
    // 단, .. 정점 번호가 작은 것을 먼저 방문하고
    // -> sort는 필수로 해야 하는 것
    for(int i=1; i<=N; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    
    
    dfs(V);
    memset(visited, 0, sizeof(int)*MAX);
    bfs(V);
    
    for(int ans : ans_dfs) cout << ans << " ";
    cout << endl;
    for(int ans : ans_bfs) cout << ans << " ";
    
}