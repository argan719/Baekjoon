#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>
#define MAX 100001
using namespace std;

int visited[MAX];
int N, K;

int bfs(){
    queue<int> q;
    q.push(N);
    visited[N] = 1;
    int step = 0;
    
    while(!q.empty()){
        int len = q.size();
        
        for(int i=0; i<len; i++){
            auto cur = q.front();
            q.pop();
        
            if(cur == K){
                cout << step;
                return 0;
            }
            
            for(auto n : {cur-1, cur+1, cur*2}){
                if(n < 0 || n > MAX-1) continue;
                if(visited[n]) continue;
                visited[n] = 1;
                q.push(n);
            }
        }
        step++;
    }
    return -1;
}
int main(void){
    cin >> N >> K;
    bfs();
}