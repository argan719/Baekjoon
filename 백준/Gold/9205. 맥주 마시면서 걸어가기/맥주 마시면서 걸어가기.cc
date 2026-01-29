#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#define MAX 101
using namespace std;

typedef struct pos{
    int x;
    int y;
}pos;


int TC, N; // 편의점 개수
pos start; // 상근 집
pos dest; // 목적지
pos store[MAX]; // 편의점

int v[MAX];


int bfs(){
    queue<pos> q;
    int dist;
    
    q.push(start);
    
    while(!q.empty()){
        pos cur = q.front();
        q.pop();
            
        // 정답처리는 이곳에서
        dist = abs(dest.x - cur.x) + abs(dest.y - cur.y);
        if(dist <= 20 * 50) return 1;
            
        // 연결 범위내 ???미방문??? 조건 맞으면
        for(int i=0; i<N; i++){
            if(v[i] !=0) continue;
                
            dist = abs(store[i].x - cur.x) + abs(store[i].y - cur.y);
            if(dist <= 20*50) {
                q.push(store[i]);
                v[i] = 1;
            }
        }
        
    }
    return 0;
}

int solve(){
    int val = abs(dest.x-start.x) + abs(dest.y - start.y); // 목적지 집
    
    if(val <= 20 * 50) return 1; // 무조건 가능
    if(N == 0 && val > 20*50) return 0; // 무조건 불가능.
    //if((N*20 + 20)*50 < val*50) return 0; // 무조건 불가능
    
    return bfs();
}

int main(){
    cin >> TC;
    for(int t=0; t<TC; t++){
        cin >> N;
        cin >> start.x >> start.y;
        for(int i=0; i<N; i++){
            cin >> store[i].x >> store[i].y;
        }
        cin >> dest.x >> dest.y;
        
        int r = solve();
        if(r == 1) cout << "happy" << endl;
        else cout << "sad" << endl;
        
        // 배열 초기화 필수.
        memset(store, 0, sizeof(store));
        memset(v, 0, sizeof(v));
    }
}
