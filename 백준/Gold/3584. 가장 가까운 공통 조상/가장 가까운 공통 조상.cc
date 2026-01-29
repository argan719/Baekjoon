#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 10001
using namespace std;

int TC;
int N;

int v1[MAX];
int v2[MAX];

int s, e;
vector<int> adj[MAX];

int bfs(int s, int e){
    queue<int> q1;
    queue<int> q2;
    int c;
    int len;
    
    // 단위작업
    q1.push(s); // s 전용 큐
    q2.push(e); // e 전용 큐
    
    v1[s] = 1;  // s 전용 visited
    v2[e] = 1;  // e 전용 visited
    
    
    while(!q1.empty() || !q2.empty()){
        len = q1.size();
        for(int i=0; i<len; i++){
            c = q1.front();
            q1.pop();
            // 정답처리는 이곳에서
            if(v2[c] == 1) return c;
            
            // 연결, 미방문 조건맞으면
            for(auto n : adj[c]){
                if(v1[n] !=0) continue;
                // 단위작업
                q1.push(n);
                v1[n] = 1;
            }
        }
        
        len = q2.size();
        for(int i=0; i<len; i++){
            c = q2.front();
            q2.pop();
            // 정답처리는 이곳에서
            if(v1[c] == 1) return c;
            
            for(auto n : adj[c]){
                if(v2[n] !=0) continue;
                
                //단위작업
                q2.push(n);
                v2[n] = 1;
            }
        }
    }
    return -1; // 이곳에 올일은 없지만..
}

int main(){
    cin >> TC;
    int A, B;
    for(int t=0; t<TC; t++){
        cin >> N;
        memset(v1, 0, sizeof(v1));
        memset(v2, 0, sizeof(v2));
        //memset(adj, 0, sizeof(adj));
        for(int i=0; i<MAX; i++) adj[i].assign(0,0);
        
        for(int i=0; i<N-1; i++){
            cin >> A >> B;
            adj[B].push_back(A);
        }
        cin >> s >> e;
        
        cout << bfs(s, e) << endl;
    }
}
