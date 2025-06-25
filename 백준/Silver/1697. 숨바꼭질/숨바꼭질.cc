#include<iostream>
#include<queue>
#include<map>
#define MAX 100001
using namespace std;

int visited[MAX];
int N, K;

void bfs(){
    queue<int> q;
    map<int, int> depth;
    q.push(N);
    visited[N] = 1;
    depth[N] = 0; // 시작 노드 깊이 설정
    
    while(!q.empty()){
        auto a = q.front();
        q.pop();
        
        if(a == K) {
            cout << depth[a];
            return;
        }
        
        if(!visited[a-1] && 0<= a-1 && a-1 <= MAX) {
            q.push(a-1);
            visited[a-1] = 1;
            depth[a-1] = depth[a] + 1;
        }
        if(!visited[a+1] && 0<= a+1 && a+1 <= MAX) {
            q.push(a+1);
            visited[a+1] = 1;
            depth[a+1] = depth[a] + 1;
        }
        if(!visited[a*2] && 0<= a*2 && a*2 <= MAX) {
            q.push(2*a);
            visited[2 * a] = 1;
            depth[2 * a] = depth[a] + 1;
        } 
    }
}

int main(void){
    cin >> N >> K;
    bfs();
}