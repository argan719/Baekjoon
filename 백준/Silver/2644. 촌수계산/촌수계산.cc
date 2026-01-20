#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 101

using namespace std;
int n, m;
int a, b;
int step;

vector<int> adj[MAX];
int visited[MAX];

// a를 기준으로 b를 찾기
int bfs(){
    queue<int> q;
    int len;
    
    q.push(a);
    visited[a] = 1;
    
    while(!q.empty()){
        len = q.size();
        
        // 현재 depth만 돌면서 본인 자식 노드 push 하고 끝나도록 - step++
        for(int i=0; i<len; i++){
            int cur = q.front();
            q.pop();
            
            // 정답 찾으면 바로 리턴.
            if(cur == b) return step;
            
            for(auto n : adj[cur]){
                if(visited[n]) continue;
                
                q.push(n);
                visited[n] = 1;
            }
        }
        step++;
    }
    
    return -1;
}

int main(){
    cin >> n;
    cin >> a >> b;
    cin >> m;
    int x,y;
    
    // 양방향 인접행렬 생성
    for(int i=0;i<m;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    cout << bfs();
    
    return 0;
}
