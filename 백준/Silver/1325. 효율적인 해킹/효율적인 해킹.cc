#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#define MAX 10001
using namespace std;

vector<int> arr[MAX];
int visited[MAX];
int N, M;

int bfs(int n){
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    int cnt = 0;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(int k=0; k<arr[cur].size(); k++){
            if(!visited[arr[cur][k]]) {
                visited[arr[cur][k]] = 1;//빼먹지말것
                q.push(arr[cur][k]);
                cnt++;
            }
        }
        
    }
    return cnt;
}

int main(void){
    cin >> N >> M;
    int A, B;
    int result[MAX];
    int r;
    
    for(int i=0; i<M; i++){
        cin >> A >> B;
        arr[B].push_back(A);
    }
    int max_val = 0;
    
    for(int i=1; i<=N; i++){
        r = bfs(i);
        memset(visited, 0, sizeof(visited));
        max_val = max(max_val, r);
        result[i] = r;
    }
    
    for(int i=1; i<=N; i++){
        if(result[i] == max_val) cout << i << " ";
    }
    
}
