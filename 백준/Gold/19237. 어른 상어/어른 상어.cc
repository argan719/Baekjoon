#include<iostream>
#include<cstring>
#include<vector>
#include<deque>
#define MAX 21
using namespace std;

int N, M, K;
int matrix[MAX][MAX];
int v[MAX][MAX];

struct Smell{
    int num=0;  // 해당 냄새를 남긴 상어의 번호
    int time=0; // 해당 냄새의 남은 지속시간
};
Smell smell[MAX][MAX];

struct Shark{
    int r, c;
    int d; // 해당 상어의 현재 방향
};
Shark shark[401];
int die[401];
int die_cnt;
//deque<Shark> shark[401];  // 1~M
int prior[401][5][5];  // 각 상어당 총 16개의 방향 우선순위 저장.

// 없음, 상, 하, 좌, 우 (1,2,3,4)
int dr[] = {0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, -1, 1};

void input(){
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> matrix[i][j];
            // 상어 정보 저장.
            if(matrix[i][j] !=0) {
                shark[matrix[i][j]].r = i;
                shark[matrix[i][j]].c = j;
            }
        }
    }
    
    for(int i=1; i<=M; i++){
        cin >> shark[i].d;
    }
    
    for(int i=1; i<=M; i++){
        for(int a=1; a<=4; a++){
            for(int b=1; b<=4; b++){
                cin >> prior[i][a][b];
            }
        }
    }
}


void solve(){
    int r,c,d;
    int nr, nc;
    int dir;
    
    // [2 -2] 상어가 새로 이동한 곳에 냄새 마킹
    // 맨 처음에는 모든 상어가 자신의 위치에 자신의 냄새를 뿌린다. 현재 k==0
    for(int i=1; i<=M; i++){
        smell[shark[i].r][shark[i].c].num = i;
        smell[shark[i].r][shark[i].c].time = K;
    }
    
    
    for(int k=1; k<=1000; k++){
        memset(v, 0, sizeof(v));
        
        // [1] 이동
        for(int i=1; i<=M; i++){
            if(die[i] == 1) continue;
            
            d = shark[i].d;
            r = shark[i].r; c = shark[i].c;
            int flag = 0;
            
            // [1] 내 우선순위를 따르면서, 인접칸 중 아무 냄새가 없는 칸 먼저 탐색.
            for(dir=1; dir<=4; dir++){
                nr = r + dr[prior[i][d][dir]]; nc = c + dc[prior[i][d][dir]];
                if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
                
                if(smell[nr][nc].time <= 0) {flag = 1; break;}
            }
            if(flag == 1){
                shark[i].r = nr; shark[i].c = nc;
                shark[i].d = prior[i][d][dir];
            }
            else{
                // [2] 아무 냄새 없는 칸이 없다면, 내 우선순위를 따르면서 자신의 냄새가 있는 칸 탐색.
                for(dir=1; dir<=4; dir++){
                    nr = r + dr[prior[i][d][dir]]; nc = c + dc[prior[i][d][dir]];
                    if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
                    
                    if(smell[nr][nc].num == i) {flag = 1; break;}
                }
                if(flag == 1){
                    shark[i].r = nr; shark[i].c = nc;
                    shark[i].d = prior[i][d][dir];
                }
            }
            
            // [2] 이동했는데, 이미 누군가 있다면 나보다 우선순위가 높은 상어일테니 나는 바로 죽음.
            if(v[shark[i].r][shark[i].c] == 1) { die[i] = 1; die_cnt++;}  //shark.erase(shark.begin() + i);
            else v[shark[i].r][shark[i].c] = 1;  // 방문처리
        }
        
        // 1번 상어만 남은 경우 정답처리 후 종료.
        if(M - die_cnt == 1) {
            cout << k << "\n";
//            for(int i=1; i<=M; i++){
//                if(die[i] == 1) cout << "죽은 상어 : " << i << "\n";
//            }
            return;
        }
        
        // 디버깅
//        cout <<"현재 " << k <<"초 \n";
//        for(int i=1; i<=N; i++){
//            for(int j=1; j<=N; j++){
//                cout << smell[i][j].time << " ";
//            }
//            cout << "\n";
//        }
        
        
        // [2] 냄새 마킹
        // [2 -1] 1초마다 냄새 1씩 삭제
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(smell[i][j].time > 0) smell[i][j].time--;
            }
        }
        
        // [2 -2] 상어가 새로 이동한 곳에 냄새 마킹
        for(int i=1; i<=M; i++){
            if(die[i] == 1) continue;
            
            smell[shark[i].r][shark[i].c].num = i;
            smell[shark[i].r][shark[i].c].time = K;
        }
        
    }
    
    // 1000초가 넘었는데 1번 상어 외에 다른 상어도 남아있는 경우
    cout << -1 << "\n";
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}