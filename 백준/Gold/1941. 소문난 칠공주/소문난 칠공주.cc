#include<iostream>
#include<cstring>
#include<queue>
#define MAX 5
using namespace std;

string arr[MAX];

int matrix[MAX][MAX]; // 7공주로 선택했다면 1로 표시
int ans;
//int v[MAX][MAX];  // BFS에서 쓰기 위한 visited 배열
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void input(){
    for(int i=0; i<5; i++){
        cin >> arr[i];
    }
}

int bfs(int r, int c){
    queue<pair<int,int>> q;
    int v[MAX][MAX] = {0, }; // 0 초기화 필요
    int cnt = 0;
    // 단위작업
    q.push({r,c});
    v[r][c] = 1;
    cnt = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        // 연결4방향
        for(int dir=0; dir<4; dir++){
            int nr = cur.first + dr[dir]; int nc = cur.second + dc[dir];
            // 범위내 미방문 조건(1) 맞으면
            if(nr < 0 || nr >= MAX || nc < 0 || nc >= MAX) continue;
            if(v[nr][nc]) continue;
            
            if(matrix[nr][nc] == 1){
                // 단위작업
                q.push({nr, nc});
                v[nr][nc] = 1;
                cnt++;
            }
        }
    }
    return (cnt == 7);
}

int check(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(matrix[i][j]) {
                return bfs(i, j);
            }
        }
    }
    return -1;
}

void dfs(int n, int cnt, int scnt){
    // 가지치기 추가
    if(cnt > 7) return;
    
    // 종료조건은 여기에서
    if(n == 25){
        if(cnt == 7 && scnt >=4) {
            // BFS로 인접 조건까지 확인 후 정답 계수
            if(check()) ans++;
        }
        return;
    }
    
    // 하부함수 호출
    // 포함하는 경우
    matrix[n/5][n%5] = 1;  // 방문처리 (7공주에 해당 학생이 포함됨 표시)
    dfs(n+1, cnt+1, scnt+(int)(arr[n/5][n%5] == 'S'));
    matrix[n/5][n%5] = 0; // 원상복구
    // 포함하지 않는 경우
    dfs(n+1, cnt, scnt);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0, 0);  // 인덱스, 전체 학생 수, 이다솜파 학생 수
    cout << ans;
}
