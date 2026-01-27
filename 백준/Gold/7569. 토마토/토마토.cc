#include<iostream>
#include<cstring>
#include<queue>
#define MAX 101
using namespace std;

int matrix[MAX][MAX][MAX];
int v[MAX][MAX][MAX];

int N, M, H;

typedef struct pos{
    int r;
    int c;
    int h;
}pos;

int dr[] = {-1, 1, 0, 0, 0, 0};
int dc[] = {0, 0, -1, 1, 0, 0};
int dh[] = {0, 0, 0, 0, -1, 1};

void input(){
    cin >> M >> N >> H;
    for(int k=0; k<H; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> matrix[i][j][k];
            }
        }
    }
}

int bfs(){
    queue<pos> q;
    int nr, nc, nh;
    int cnt = 0; // 익지 않은 토마토 개수
    
    // 단위작업 - 익은 토마토 전부 push
    for(int k=0; k<H; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(matrix[i][j][k] == 1) {
                    q.push({i, j, k});
                    v[i][j][k] = 1;
                }
                else if(matrix[i][j][k] == 0) cnt++;
            }
        }
    }
    
    if(cnt == 0) return 0; // 모든 토마토가 익어있는 상태
    
    pos c;
    while(!q.empty()){
        c = q.front();
        q.pop();
        
        // 연결 6방향
        for(int i=0; i<6; i++){
            nr = c.r + dr[i];
            nc = c.c + dc[i];
            nh = c.h + dh[i];
            
            // 범위내 미방문 조건맞으면 (==0)
            if(nr < 0 || nr >=N || nc < 0 || nc >=M || nh < 0 || nh >= H) continue;
            if(v[nr][nc][nh] != 0) continue;
            if(matrix[nr][nc][nh] == 0){
                // 단위작업
                q.push({nr, nc, nh});
                v[nr][nc][nh] = v[c.r][c.c][c.h] + 1;
                cnt--;
            }
        }
    }
    if(cnt == 0) return v[c.r][c.c][c.h] - 1;
    else return -1;
    
}

int main(){
    input();
    
    cout << bfs();
}
