#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 101
using namespace std;

int N, M;
int S, E;
vector<int> adj[MAX];
int v[MAX];

void input(){
    int x,y;
    cin >> N;
    cin >> S >> E;
    cin >> M;
    
    for(int i=0; i<M; i++){
        cin >> x >> y;
        // 양방향으로 구성
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

int bfs(){
    queue<int> q;
    // 단위작업
    q.push(S);
    v[S] = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        // 정답처리는 이곳에서
        if(cur == E) return v[cur] - 1;
        
        // 연결 범위내 미방문 조건맞으면
        for(int n : adj[cur]){
            if(v[n] != 0) continue;
            
            //단위작업
            q.push(n);
            v[n] = v[cur] + 1;
        }
    }
    // 촌수 계산 불가
    return -1;
}

int main(){
    input();
    
    cout << bfs();
}