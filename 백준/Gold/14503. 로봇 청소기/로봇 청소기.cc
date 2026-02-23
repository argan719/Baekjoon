#include<iostream>
#include<cstring>
#define MAX 51
using namespace std;

int N, M;
int r, c;
int d;
int ans;

// 상 우 하 좌
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int matrix[MAX][MAX];
int v[MAX][MAX];

void input(){
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> matrix[i][j];
        }
    }
}
// 청소되지 않은 빈칸임을 확인하는 함수
bool isValid(int nr, int nc){
    // 범위내 미방문 조건(빈칸이면) - 범위내는 사실 필요없는 조건
    if(nr < 0 || nr >=N || nc < 0 || nc >= M) return false;
    if(v[nr][nc]) return false;
    if(matrix[nr][nc]) return false;
    
    return true;
}

void solve(){
    
    while(1){
        if(v[r][c] == 0 && matrix[r][c] == 0) {
            ans++;
            v[r][c] = 1; // 방문처리
        }
        bool valid = false;
        
        for(int dir=0; dir<4; dir++){
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            
            if(isValid(nr,nc)){
                valid = true;
                bool flag = true;
                while(flag){
                    // 반시계 90도 회전
                    d = (d - 1 + 4) % 4;
                    nr = r + dr[d];
                    nc = c + dc[d];
                    // 전진 가능 여부
                    if(isValid(nr,nc)) {
                        r = nr; c = nc;
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
        }
        
        // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        if(!valid){
            int nr = r - dr[d];
            int nc = c - dc[d];
            
            // 후진 가능 여부만 따지면 됨. 즉, 빈칸인지 벽인지만 따지면 됨.
            if(nr < 0 || nr >=N || nc < 0 || nc >= M) return;
            if(matrix[nr][nc]) return;
            r = nr, c = nc;
        }
        
    }
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    cout << ans << "\n";
}
