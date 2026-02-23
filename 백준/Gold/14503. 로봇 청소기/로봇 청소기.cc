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

void input(){
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> matrix[i][j];
        }
    }
}

void solve(){
    
    while(1){
        if(matrix[r][c] == 0){
            ans++;
            matrix[r][c] = 2; // 방문처리 (청소한 빈칸)
        }
        bool flag = false;
        
        // 현재 칸의 주변4칸 중 미청소 구역 있는 경우, 회전 -> 전진
        for(auto nd : {(d+3)%4, (d+2)%4, (d+1)%4, d}){
            int nr = r + dr[nd], nc = c + dc[nd];
            if(matrix[nr][nc] == 0) {
                r = nr, c = nc; d = nd;
                flag = true;
                break;
            }
        }
        // 현재 칸의 주변4칸 중 미청소 구역 없는 경우, 후진
        if(!flag){
            int nr = r - dr[d]; int nc = c - dc[d];
            if(matrix[nr][nc] != 1) { // 벽만 아니라면!!
                r = nr; c = nc;
            }
            else return; // 작동을 멈춘다
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    cout << ans << "\n";
}