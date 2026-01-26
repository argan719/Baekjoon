#include<iostream>
#include<queue>
#include<cstring>
#define MAX 101
using namespace std;
int N;
int matrix[MAX][MAX];
int v[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(int r, int c){
    queue<pair<int, int>> q;
    int nr,nc;
    // 단위작업
    q.push(make_pair(r, c));
    v[r][c] = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        // 연결 4방향
        for(int i=0; i<4; i++){
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            
            if(nr < 0 || nr >=N || nc < 0 || nc >= N) continue;
            if(v[nr][nc] !=0) continue;
            // 조건 맞으면 단위작업.
            q.push(make_pair(nr, nc));
            v[nr][nc] = 1;
        }
    }
}

int main(){
    int max_h = 0;
    int result = 0;
    int h;
    int cnt;
    
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> h;
            matrix[i][j] = h;
            if(max_h < h) max_h = h;
        }
    }
    
    for(int H=100; H >=0; H--){ // >= 0??
        // 매번 초기화 필요 변수
        cnt = 0;
        memset(v, 0, sizeof(v));
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){ // 잠김 표시
                if(matrix[i][j] <= H) v[i][j] = 1;
            }
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(v[i][j] == 0) { bfs(i,j); cnt++;}
            }
        }
        if(result < cnt) result = cnt;
    }
    
    cout << result;
    return 0;
}