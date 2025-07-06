#include<iostream>
#include<queue>
#define MAX 100001
using namespace std;

int N;
vector<int> adj[MAX];
int visited[MAX];

void bfs(){
    queue<int> q;
    q.push(1);
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(auto idx : adj[cur]){
            if(visited[idx] != 0) continue;
            visited[idx] = cur;
            q.push(idx);
        }
    }
    
}

int main(void){
    int a,b;
    cin >> N;
    
    for(int i=1; i<=N-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs();
    for(int i=2; i<=N; i++){
        cout << visited[i] << "\n";
    }
}
