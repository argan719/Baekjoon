#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 1001
using namespace std;

int N, M;
int matrix[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> matrix[i][j];
        }
    }
}

void bfs(int r, int c){
    queue<pair<int, int>> q;
    int nr, nc;
    // 단위작업
    q.push(make_pair(r, c));
    matrix[r][c] = 1; // 방문처리
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        // 연결 4방향
        for(int i=0; i<4; i++){
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            // 범위내(상관X) 미방문 조건맞으면
            if(nr < 0) nr = N-1;
            if(nr >=N) nr = 0;
            if(nc < 0) nc = M-1;
            if(nc >=M) nc = 0;
            
            if(matrix[nr][nc] == 0) {
                // 단위작업
                q.push(make_pair(nr, nc));
                matrix[nr][nc] = 1;
            }
        }
    }
}

int main(){
    input();
    
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix[i][j] == 0) { bfs(i,j); cnt++;}
        }
    }
    
    cout << cnt;
    return 0;
}
