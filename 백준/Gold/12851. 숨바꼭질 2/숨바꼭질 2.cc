#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define MAX 100001 // 10^5
using namespace std;

int v[MAX];
int cnt[MAX];
int N, K;
int min_time;

void input(){
    cin >> N >> K;
}

void bfs(){
    queue<int> q;
    // 단위작업
    q.push(N);
    v[N] = 1;
    cnt[N] = 1;
    
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        // 정답처리는 이곳에서
        //if(cur == K) return v[cur] - 1;
        
        // 연결 범위내 미방문 (조건) 맞으면
        for(auto n : {cur-1, cur+1, 2*cur}){
            if(n < 0 || n > 100000) continue;
            
            if(v[n] !=0) {
               if(v[n] == v[cur] + 1) cnt[n]+= cnt[cur];
            }else{
                q.push(n);
                v[n] = v[cur] + 1;
                cnt[n] = cnt[cur];
            }
            
        }
    }
    cout << v[K] - 1 << endl;
    cout << cnt[K] << endl;
    
}



int main(){
    input();
    
    bfs();
    
    return 0;
}
