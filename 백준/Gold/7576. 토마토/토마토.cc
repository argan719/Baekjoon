#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAX 1001
using namespace std;

int N, M;
int matrix[MAX][MAX];
int v[MAX][MAX];

int cnt_y; // 익은 토마토 전체 개수
int cnt_n; // 익은X 토마토 전체 개수
int blank; // 비어있는 칸 수

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

void input(){
    int r;
    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> r;
            matrix[i][j] = r;
            if(r == 1) cnt_y++;
            else if(r == 0) cnt_n++;
            else if(r == -1) blank++;
        }
    }
}

int bfs(){
    queue<pair<int,int>> q;
    int nr, nc;
    int step = 0;
    // 단위작업 - 익은 토마토를 전부 push
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix[i][j] == 1) {
                q.push(make_pair(i, j));
                v[i][j] = 1;
            }
        }
    }
    
    while(!q.empty()){
        int len = q.size();
        
        for(int l=0; l<len; l++){
            auto cur = q.front();
            q.pop();
            
            // 정답처리는 이곳에서? -> 안됨.
            //if(cnt_n == 0) return step;
            
            for(int i=0; i<4; i++){
                nr = cur.first + dr[i];
                nc = cur.second + dc[i];
                // 범위내 미방문 조건(익지 않은 토마토) 맞으면
                if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                if(v[nr][nc]) continue;
                
                if(matrix[nr][nc] == 0) {
                    // 단위작업
                    q.push(make_pair(nr,nc));
                    v[nr][nc] = 1;
                    cnt_n--;
                    if(cnt_n == 0) return step+1;
                }
            }
        }
        step++;
    }
    // 토마토가 모두 익지는 못하는 상황이면..
    return -1;
}

int main(){
    input();
    // 저장될 때부터 모든 토마토가 익어있는 상태
    //if(cnt_y == N*M - blank) cout << 0;
    if(cnt_n == 0) cout << 0;
    //else if(cnt_n == N*M - blank) cout << -1; 잘못된 조건임.
    else{
        cout << bfs();
    }
        
    return 0;
}