#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define MAX 51
using namespace std;

string matrix[MAX];
int v[MAX][MAX];
int N, M;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> matrix[i];
    }
}

int bfs(int r, int c){
    queue<pair<int,int>> q;
    int nr,nc;
    // 단위작업
    q.push(make_pair(r, c));
    v[r][c] = 1;
    
    auto cur = q.front();
    while(!q.empty()){
        cur = q.front();
        q.pop();
        // 연결 4방향
        for(int i=0; i<4; i++){
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            // 범위내 미방문 조건(==육지이면) 맞으면
            if(nr < 0 || nr >= N || nc < 0 || nc >=M) continue;
            if(v[nr][nc] !=0 ) continue;
            if(matrix[nr][nc] == 'L'){
                // 단위작업
                q.push(make_pair(nr, nc));
                v[nr][nc] = v[cur.first][cur.second] + 1;
            }
        }
    }
    return v[cur.first][cur.second] - 1;
}

int main(){
    input();
    
    int r;
    int max_val = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix[i][j] == 'L'){
                
                if(i-1 >= 0 && i+1 < N && matrix[i-1][j] == 'L' && matrix[i+1][j] == 'L') continue;
                if(j-1 >= 0 && j+1 < M && matrix[i][j-1] == 'L' && matrix[i][j+1] == 'L') continue;
                memset(v, 0, sizeof(v));
                r = bfs(i, j);
                if(max_val < r) max_val = r;
            }
        }
    }
    cout << max_val;
}
