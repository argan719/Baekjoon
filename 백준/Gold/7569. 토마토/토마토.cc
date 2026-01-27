#include<iostream>
#include<vector>
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

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int dh[] = {-1, 1};

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
    pos tmp;
    int cnt = 0; // 익지 않은 토마토 개수
    
    // 단위작업 - 익은 토마토 전부 push
    for(int k=0; k<H; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(matrix[i][j][k] == 1) {
                    tmp.r = i; tmp.c = j; tmp.h = k;
                    q.push(tmp);
                    v[i][j][k] = 1;
                }
                else if(matrix[i][j][k] == 0) cnt++;
            }
        }
    }
    
    if(cnt == 0) return 0; // 모든 토마토가 익어있는 상태
    
    pos cur = q.front();
    while(!q.empty()){
        cur = q.front();
        q.pop();
        
        // 연결 4방향
        for(int i=0; i<4; i++){
            nr = cur.r + dr[i];
            nc = cur.c + dc[i];
            
            // 범위내 미방문 조건맞으면 (==0)
            if(nr < 0 || nr >=N || nc < 0 || nc >=M) continue;
            if(v[nr][nc][cur.h] != 0) continue;
            if(matrix[nr][nc][cur.h] == 0){
                // 단위작업
                q.push({nr, nc, cur.h});
                v[nr][nc][cur.h] = v[cur.r][cur.c][cur.h] + 1;
                cnt--;
            }
        }
        
        // 연결 2방향
        for(int i=0; i<2; i++){
            nh = cur.h + dh[i];
            // 범위내 미방문 조건맞으면 (==0)
            if(nh < 0 || nh >= H) continue;
            if(v[cur.r][cur.c][nh] !=0) continue;
            if(matrix[cur.r][cur.c][nh] == 0){
                q.push({cur.r, cur.c, nh});
                v[cur.r][cur.c][nh] = v[cur.r][cur.c][cur.h] + 1;
                cnt--;
            }
        }
    }
    if(cnt == 0) return v[cur.r][cur.c][cur.h] - 1;
    else return -1;
    
}

int main(){
    input();
    
    cout << bfs();
}