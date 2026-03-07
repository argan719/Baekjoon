#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAX 100001
using namespace std;
int N, K;
int v[MAX];

int ans_time;
vector<int> ans;
int parent[MAX];

void input(){
    cin >> N >> K;
}

void solve(){
    // [1] BFS - 동생 최단 찾기
    queue<int> q;
    q.push(N);
    v[N] = 1;
    parent[N] = -1;  // N의 부모는 없음.
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        // 정답처리
        if(cur == K) {
            cout << v[cur] - 1 << "\n";
            
            for(int i=cur; i!=-1; i = parent[i]){
                ans.push_back(i);
            }
            reverse(ans.begin(), ans.end());
            for(int n : ans) cout << n << " ";
            return;
        }
        
        for(int n : {cur - 1, cur + 1, cur *2}){
            if(n < 0 || n >= MAX) continue;
            if(v[n]) continue;
            
            q.push(n);
            v[n] = v[cur] + 1;
            parent[n] = cur;  // n의 부모는 cur
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}
