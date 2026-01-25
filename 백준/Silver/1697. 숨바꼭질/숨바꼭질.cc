#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define MAX 100001
using namespace std;

int v[MAX];
int N, K;

int bfs(){
    queue<int> q;
    // 단위작업
    q.push(N);
    v[N] = 0;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        if(cur == K) return v[cur];
        
        for(auto n : {cur-1, cur+1, cur*2}){
            // 범위 체크 먼저 한 뒤 방문처리 해야함!!!
            if(n < 0 || n >= MAX || v[n] !=0) continue; // 범위!!
            
            // 조건 맞으면 단위작업
            q.push(n);
            v[n] = v[cur]+1;
        }
    }
    return 0; // 올일 없지만
}

int main(){
    cin >> N >> K;
    cout << bfs();
    return 0;
}
