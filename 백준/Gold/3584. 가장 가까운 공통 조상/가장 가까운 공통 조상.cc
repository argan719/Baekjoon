#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#define MAX 10001
using namespace std;

int N;
int v[MAX];
vector<int> adj[MAX];  // 초기화???
int T;
int s,e;


int bfs(int s){
    queue<int> q;
    if(v[s] !=0) return s;
    q.push(s);
    v[s] = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(auto n : adj[cur]){
            if(v[n] !=0) return n;
            
            q.push(n);
            v[n] = 1;
        }
    }
    return 0;
}

void input(){
    int A, B;
    cin >> T;
    for(int t=0; t<T; t++){
        memset(v, 0, sizeof(v));
        for(int i=0; i<MAX; i++) adj[i].assign(0,0);  // ??
        
        cin >> N;
        for(int i=0; i<N-1; i++){
            cin >> A >> B;
            adj[B].push_back(A);
        }
        cin >> s >> e;
        
        bfs(s);
        cout << bfs(e) << endl;
    }
}


int main(){
    input();
    return 0;
}
