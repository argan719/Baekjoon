#include<iostream>
#include<cstring>
#include<queue>
#define MAX 1000001
using namespace std;

int F,S,G,U,D;
int v[MAX];

int bfs(){
    queue<int> q;
    q.push(S);
    v[S] = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        // 정답처리는 이곳에서
        if(cur == G) return v[cur] - 1;
        
        // 연결 2방향
        for(int n : {cur + U, cur - D}){
            // 범위내 미방문 조건맞으면
            if(n >= 1 && n <= F && !v[n]) {
                q.push(n);
                v[n] = v[cur] + 1;
            }
        }
    }
    // 도달못한 경우
    return -1;
}

int main(){
    cin >> F >> S >> G >> U >> D;
    
    if((U == 0 && S < G) || (D == 0 && S > G)) cout << "use the stairs";
    else {
        int r = bfs();
        if(r == -1) cout << "use the stairs";
        else cout << r;
    }
        
    return 0;
}