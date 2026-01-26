#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 101
using namespace std;

int N;
string matrix[MAX];
int v[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> matrix[i];
    }
}

int bfs(int r, int c){
    queue<pair<int, int>> q;
    int nr, nc;
    // 단위작업
    q.push(make_pair(r, c));
    v[r][c] = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        // 연결 4방향
        for(int i=0; i<4; i++){
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            // 범위 내 미방문 조건(같은 색) 맞으면
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(v[nr][nc] !=0) continue;
            
            if(matrix[nr][nc] == matrix[cur.first][cur.second]) {
                // 단위작업
                q.push(make_pair(nr, nc));
                v[nr][nc] = 1;
            }
        }
    }
    return 1;
}

int solve(){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(v[i][j] !=0) continue;
            bfs(i, j);
            cnt++;
        }
    }
    return cnt;
}

int main(){
    input();
    
    cout << solve() << " ";

    memset(v, 0, sizeof(v));
    
    // 적록색약을 위해 그냥 원본 'G'를 'R'로 교체
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(matrix[i][j] == 'G') matrix[i][j] = 'R';
        }
    }
    
    cout << solve();
    return 0;
}