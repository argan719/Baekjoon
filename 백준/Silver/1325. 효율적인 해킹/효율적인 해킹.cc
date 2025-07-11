#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define MAX 10001
using namespace std;

int N, M;
vector<int> vec[MAX];
int visited[MAX];
int result[MAX];

int bfs(int n){
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    int cnt = 0;
    
 //   for(auto cur: vec[n]){
  //      q.push(cur);
   //     cnt++;
   //     visited[cur] = 1;
  //  }
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(auto a : vec[cur]){
            if(!visited[a]) {
                visited[a] = 1;
                q.push(a);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void) {
    cin >> N >> M;
    int A, B;
    
    int max_n = 0;
    int r;
    
    for(int i=0; i<M; i++){
        cin >> A >> B;
        vec[B].push_back(A);
    }
    for(int i=1; i<=N; i++){
        result[i] = bfs(i);
        if(max_n < result[i]) max_n = result[i];
        memset(visited, 0, sizeof(visited));
    }
    
    for(int i=1; i<=N; i++){
        if(result[i] == max_n) cout << i << " ";
    }
    
}