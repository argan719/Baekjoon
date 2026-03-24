#include<iostream>
#include<queue>
#include<cstring>
#define MAX 21
using namespace std;

int N, M, K;
int cr, cc;  // 주사위가 위치한 현재 좌표
int d; // 주사위의 현재 방향

int matrix[MAX][MAX];
int v[MAX][MAX];
int ans;

// 주사위 전개도 회전
int left_right[2][2];
int up_down[2][2];
int dice[4][3]; // 전개도 전체.

// 북 동 남 서 (상 우 하 좌)
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int A, B;

void input(){
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> matrix[i][j];
        }
    }
    // 주사위 초기 설정.
    cr = 1; cc = 1;
    d = 1;
    
    left_right[0][0] = 4;
    left_right[0][1] = 1;
    left_right[1][0] = 6; // 아랫면
    left_right[1][1] = 3;
    
    up_down[0][0] = 2;
    up_down[0][1] = 1;
    up_down[1][0] = 6; // 아랫면
    up_down[1][1] = 5;
    
    dice[0][1] = 2;
    dice[1][0] = 4; dice[1][1] = 1; dice[1][2] = 3;
    dice[2][1] = 5;
    dice[3][1] = 6;
}

int change_dice(){
    int tmp[2][2];
    memset(tmp, 0, sizeof(tmp));
    
    // 방금 한 이동이 북쪽인 경우
    if (d == 0){
        // updown 반시계 회전
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                tmp[i][j] = up_down[j][2 - 1 - i];
            }
        }
        
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                up_down[i][j] = tmp[i][j];
            }
        }
        
    }
    else if(d == 1){ // 동쪽인 경우
        // leftright 시계 회전
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                tmp[i][j] = left_right[2 - 1 - j][i];
            }
        }
        
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                left_right[i][j] = tmp[i][j];
            }
        }
    }
    else if(d == 2){ // 남쪽인 경우
        // updown 시계 회전
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                tmp[i][j] = up_down[2 - 1 - j][i];
            }
        }
        
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                up_down[i][j] = tmp[i][j];
            }
        }
    }
    else if(d == 3){ // 서쪽인 경우
        // leftright 반시계 회전
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                tmp[i][j] = left_right[j][2 - 1 - i];
            }
        }
        
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                left_right[i][j] = tmp[i][j];
            }
        }
    }
    
    if(d == 1 || d == 3){
        dice[1][0] = left_right[0][0];
        dice[1][1] = left_right[0][1];
        dice[3][1] = left_right[1][0];
        dice[1][2] = left_right[1][1];
        
        up_down[0][1] = dice[1][1];
        up_down[1][0] = dice[3][1];
    }
    else{
        dice[0][1] = up_down[0][0];
        dice[1][1] = up_down[0][1];
        dice[3][1] = up_down[1][0];
        dice[2][1] = up_down[1][1];
        
        left_right[0][1] = dice[1][1];
        left_right[1][0] = dice[3][1];
    }
    
    
    if(up_down[1][0] != left_right[1][0]) return -1;
    else return dice[3][1];  // 주사위 아랫면 숫자 반환
}

void bfs(){
    queue<pair<int,int>> q;
    memset(v, 0, sizeof(v));
    int C = 0;
    // 단위작업
    q.push({cr, cc});
    v[cr][cc] = 1;
    B = matrix[cr][cc];
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        C++;
        
        // 연결 4방향
        for(int dir=0; dir<4; dir++){
            int nr = cur.first + dr[dir]; int nc = cur.second + dc[dir];
            if(nr < 1 || nr > N || nc < 1 || nc > M) continue;
            if(v[nr][nc] == 1) continue;
            
            if(matrix[nr][nc] == B) {
                q.push({nr,nc});
                v[nr][nc] = 1;
            }
        }
    }
    // 점수 누적.
    ans += (B * C);
}

void solve(){
    for(int i=1; i<=K; i++){
        // 주사위 위치 변경 (한칸이동)
        int nr = cr + dr[d]; int nc = cc + dc[d];
        // 범위 밖인 경우
        if(nr < 1 || nr > N || nc < 1 || nc > M) {
            d = (d+2)%4;
            nr = cr + dr[d]; nc = cc + dc[d];
        }
        cr = nr; cc = nc;
        
        // 주사위 전개도 변경
        int bottom = change_dice();
        //cout << "현재 주사위 아랫면 : " << bottom << "\n";
        
        // 점수 획득
        bfs();
        
        // 주사위 아랫면과 비교하여 이동 방향 변경
        A = bottom;
        B = matrix[cr][cc];

        if(A > B) d = (d+1)%4;
        if(A < B) d = (d-1+4)%4;
    }
    cout << ans <<"\n";
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}
