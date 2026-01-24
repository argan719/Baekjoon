#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 100001
using namespace std;

vector<int> adj[MAX];
int ans[MAX];
int N;

int bfs(){
    queue<int> q;
    q.push(1);
    ans[1] = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(auto n : adj[cur]){
            if(ans[n] !=0) continue;
            // 단위작업
            q.push(n);
            ans[n] = cur;
        }
    }
    return 0;
}


int main(){
    int a,b;
    cin >> N;
    for(int i=1; i<=N-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs();
    
    for(int i=2; i<=N; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
