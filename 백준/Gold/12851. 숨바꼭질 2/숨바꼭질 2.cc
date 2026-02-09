#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 100001
using namespace std;

int N, K;
int v[MAX];
int cnt;

void input(){
    cin >> N >> K;
}

int bfs(){
    queue<int> q;
    q.push(N);
    v[N] = 1;
    
    while(!q.empty()){
        int len = q.size();
        
        for(int i=0; i<len; i++){
            int cur = q.front();
            q.pop();
            
            // 정답처리는 이곳에서 (종료하면 안됨)
            if(cur == K) cnt++;
            
            // 연속 범위내 미방문 조건 맞으면
            for(auto n : {cur - 1, cur + 1, 2 * cur}){
                if(n < 0 || n > 100000) continue;
                
                if(!v[n] || v[n] == v[cur] + 1){
                    q.push(n);
                    v[n] = v[cur] + 1;
                }
            }
        }
        
        if(cnt > 0) return 1;
        
    }
    // 이곳에 올일은 없지만..
    return -1;
}

int main(){
    input();
    bfs();
    cout << v[K] - 1 << endl;
    cout << cnt << endl;
}