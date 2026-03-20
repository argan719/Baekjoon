#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX 105
using namespace std;
int N;
int matrix[MAX][MAX]; // -1으로 패딩
int v[MAX][MAX];
int vv[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int ans = 300;

void input(){
    cin >> N;
    memset(matrix, -1, sizeof(matrix));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> matrix[i][j];
        }
    }
}
void bfs_numbering(int i, int j, int val){
    queue<pair<int,int>> q;
    q.push({i,j});
    v[i][j] = 1;
    matrix[i][j] = val;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(int dir=0; dir<4; dir++){
            int nr =  cur.first + dr[dir]; int nc = cur.second + dc[dir];
            if(v[nr][nc]) continue;
            if(matrix[nr][nc] == 1) {
                q.push({nr,nc});
                v[nr][nc] = 1;
                matrix[nr][nc] = val;
            }
        }
    }
}

int bfs(int val){
    memset(v, 0, sizeof(v));
    memset(vv, 0, sizeof(vv));
    queue<pair<int,int>> q;
    //int ans_min = 300;
    
    // 우선 해당번호에 해당하면 전부 push
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(matrix[i][j] == val) {
                q.push({i,j});
                v[i][j] = -1;
                vv[i][j] = 1;  // 진짜 방문처리 용도
            }
        }
    }
    
    // 다리 놓기
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
//        // 정답처리 => 최솟값 갱신
//        if(matrix[cur.first][cur.second] != val && matrix[cur.first][cur.second] != 0){
//            if(ans > v[cur.first][cur.second]) ans = v[cur.first][cur.second];
//        }
        
        // 연결 4방향
        for(int dir=0; dir<4; dir++){
            int nr = cur.first + dr[dir]; int nc = cur.second + dc[dir];
            if(matrix[nr][nc] < 0) continue;  // 범위내
            if(vv[nr][nc] == 1) continue;
            
            if(matrix[nr][nc] != val && matrix[nr][nc] != 0){
                return v[cur.first][cur.second] + 1;
            }
            
            // 단위작업
            q.push({nr,nc});
            v[nr][nc] = v[cur.first][cur.second] + 1;
            vv[nr][nc] = 1;
        }
    }
    // 이곳에 올일은 없지만..
    return -1e8;
}


void solve(){
    // [1] 단지번호 매기기
    int cnt = 1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(v[i][j] == 1) continue;
            if(matrix[i][j] == 0) continue;
            
            bfs_numbering(i, j, cnt++);
        }
    }

    // [2] 최솟값 구하기
    for(int val = 1; val < cnt; val++){
        ans = min(ans, bfs(val));
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}
