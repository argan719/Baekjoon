#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define MAX 1001
using namespace std;

int T;
int R, C; // N, M

int matrix[MAX][MAX];
int v[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int preprocess(){
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(matrix[i][j] >= T) matrix[i][j] = 255;
            else if(matrix[i][j] < T) matrix[i][j] = 0;
        }
    }
    return 1;
}

int bfs(int r, int c){
    queue<pair<int, int>> q;
    int nr, nc;
    // 단위작업
    q.push(make_pair(r,c));
    v[r][c] = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        // 연결 4방향
        for(int i=0; i<4; i++){
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(v[nr][nc] || matrix[nr][nc] != 255) continue;
            
            // 조건 맞으면 단위작업
            q.push(make_pair(nr, nc));
            v[nr][nc] = 1;
        }
    }
    return 1;
}

int main(){
    int cnt = 0;
    int r, g, b;
    
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> r >> g >> b;
            matrix[i][j] = (r+g+b)/3;
        }
    }
    
    cin >> T;
    // 픽셀 값 전처리 - 255 or 0
    preprocess();
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(matrix[i][j] != 255 || v[i][j]) continue;
            //if(matrix[i][j] == 255 && !v[i][j])
            bfs(i, j);  // visited를 채워가는 역할만 수행.
            cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}
