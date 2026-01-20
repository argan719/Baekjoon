// 2644
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 101

using namespace std;
int n, m;
int a, b;
//int result = -1;
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
        
        for(int i=0; i<len; i++){
            int cur = q.front();
            q.pop();
            
            if(cur == b) return 1;
            
            for(auto n : adj[cur]){
                if(visited[n]) continue;
                
                q.push(n);
                visited[n] = 1;
            }
        }
        step++;
    }
    // 못 찾은 경우 = 메인에서 -1을 출력해야함.
    return 0;
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
    
    // depth result 처리 필요.
    if(bfs()) cout << step;
    else cout << -1;
    
    return 0;
}