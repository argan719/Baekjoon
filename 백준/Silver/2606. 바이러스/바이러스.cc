// 공간 생각해서 벡터 배열로 구현 연습
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#define MAX 101
using namespace std;

vector<int> adj[MAX];
int cnt;
int visited[MAX];
int N;

void bfs(){
    queue<int> q;
    // 문제 조건 상 항상 1번부터 시작
    // 단위작업
    q.push(1);
    visited[1] = 1;
    // 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수이므로 1번 컴퓨터는 카운트 제외.
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int n : adj[cur]){
            if(visited[n]) continue;
            
            //  범위내 미방문 조건 맞으면
            //  단위작업
            q.push(n);
            visited[n] = 1;
            cnt++;
        }
    }
    
    
}

int main(){
    cin >> N;
    int n;
    int r, c;
    cin >> n;
    // 양방향 인접행렬 생성
    for(int i=0;i<n; i++){
        cin >> r >> c;
        adj[r].push_back(c);
        adj[c].push_back(r);
    }
    
    bfs();
    cout << cnt;
    return 0;
}