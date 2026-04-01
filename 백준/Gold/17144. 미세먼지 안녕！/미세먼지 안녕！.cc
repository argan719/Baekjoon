#include<iostream>
#include<cstring>
#include<queue>
#define MAX 55
using namespace std;

int N, M, T;
int matrix[MAX][MAX];
int tmp[MAX][MAX];

struct pos{
    int r,c;
};
int first, second;  // 공기청정기 윗부분, 아랫부분 행 좌표

// 우 하 좌 상
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int ans;

void input(){
    cin >> N >> M >> T;
    memset(matrix, -1, sizeof(matrix));
    int flag = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M;j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == -1){
                if(flag == 0) {
                    flag = 1;
                    first = i;
                }
                else second = i;
                matrix[i][j] = 0;  // 0으로 변환.
            }
        }
    }
}

void solve(){
    for(int t=1; t<=T; t++){
        // [1] 미세먼지 확산
        memset(tmp, 0, sizeof(tmp));
        
        for(int r=1; r<=N; r++){
            for(int c=1; c<=M; c++){
                // 미세먼지가 있다면 확산.
                if(matrix[r][c] > 0) {
                    int cnt = 0;
                    for(int dir=0; dir<4; dir++){
                        int nr =  r + dr[dir]; int nc = c + dc[dir];
                        if(matrix[nr][nc] == -1) continue;
                        if(nc == 1 && (nr == first || nr == second)) continue;
                        tmp[nr][nc] += matrix[r][c]/5;
                        cnt++;
                    }
                    tmp[r][c] += matrix[r][c] - (matrix[r][c]/5) * cnt;
                }
            }
        }
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M;j++){
                matrix[i][j] = tmp[i][j];
            }
        }
 
        // [2] 공기청정기 바람 순환
        // 아랫 바람부터 - 시계 방향
        //memset(tmp, 0, sizeof(tmp));
        int ci, cj, d, ni, nj;
        d = 0; ci = second; cj = 1;
        while(1){
            ni = ci + dr[d]; nj = cj + dc[d];
            // 공기청정기 좌표로 돌아왔다면 - 종료
            if(ni == second && nj == 1) {
                // 공기청정기 처리
                //tmp[ni][nj] = -1;
                break;
            }
            
            if(matrix[ni][nj] == -1) {
                d = (d+1)%4;
                ni = ci + dr[d]; nj = cj + dc[d];
            }
            //if(matrix[ci][cj] == -1) tmp[ni][nj] = 0;
            tmp[ni][nj] = matrix[ci][cj];
            ci = ni; cj = nj;
        }
        
        // 윗바람
        d = 0; ci = first; cj = 1;
        while(1){
            ni = ci + dr[d]; nj = cj + dc[d];
            // 공기청정기 좌표로 돌아왔다면 - 종료
            if(ni == first && nj == 1) {
                // 공기청정기 처리
                //tmp[ni][nj] = -1;
                break;
            }
            // 범위 밖이라면 - 방향 전환
            if(matrix[ni][nj] == -1) {
                d = (d-1+4)%4;
                ni = ci + dr[d]; nj = cj + dc[d];
            }
            //if(matrix[ci][cj] == -1) tmp[ni][nj] = 0;
            tmp[ni][nj] = matrix[ci][cj];
            ci = ni; cj = nj;
        }
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M;j++){
                matrix[i][j] = tmp[i][j];
            }
        }
        
    }
    
    // T초 후 정답처리.
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(matrix[i][j] <= 0) continue;
            ans += matrix[i][j];
        }
    }
    cout << ans;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}