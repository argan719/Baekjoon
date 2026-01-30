#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define MAX 100001
using namespace std;

int v[MAX];
int N, K;
int min_time;
int cnt = 0;

void input(){
    cin >> N >> K;
}

int bfs(){
    queue<int> q;
    int result;
    // 단위작업
    q.push(N);
    v[N] = 1;
    
    while(!q.empty()){
        int len = q.size();
        
        for(int i=0; i<len; i++){
            int cur = q.front();
            q.pop();
            
            // 정답처리는 이곳에서
            if(cur == K) {
                result = v[cur] - 1;
                cnt++;
            }
            
            // 연결 범위내 미방문 (조건) 맞으면
            for(auto n : {cur-1, cur+1, 2*cur}){
                if(n < 0 || n > 100000) continue;
                if(v[n] == 0 || v[n] == v[cur] + 1) {
                    // v[n] = v[cur] + 1인 경우에도 push를 하는 이유는
                    // 같은 step에서 가는 경우 다른 경로지만 둘다 답이 될 수 있기 때문.
                    q.push(n);
                    v[n] = v[cur] + 1;
                }
            }
        }
        
        if(cnt > 0) return result; // 더 step을 진행할 이유가 없음.
    }
    //이곳에 올일은 없지만..
    return -1;
}


int main(){
    input();
        
    cout << bfs() << endl;
    cout << cnt << endl;
    
    return 0;
}
