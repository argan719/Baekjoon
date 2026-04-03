// 1463 BFS
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#define MAX (int)(1e6 + 1)
using namespace std;

int N;
vector<int> nums;
int v[MAX];

int bfs(){ // N -> 1
    queue<int> q;
    q.push(N);
    v[N] = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        // 정답처리는 이곳에서
        if(cur == 1) return v[1] - 1;
        
        if(cur % 3 == 0 && v[cur/3] == 0){
            v[cur/3] = v[cur] + 1;
            q.push(cur/3);
        }
        
        if(cur % 2 == 0 && v[cur/2] == 0){
            v[cur/2] = v[cur] + 1;
            q.push(cur/2);
        }
        
        if(cur - 1 > 0 && v[cur-1] == 0){
            v[cur-1] = v[cur] + 1;
            q.push(cur-1);
        }
    }
    // 이곳에 올일은 없지만
    return -1;
}

void solve(){
    int ans = bfs();
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    solve();
}
