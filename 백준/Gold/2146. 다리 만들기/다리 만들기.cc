#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#define MAX 101
using namespace std;

int N;
int matrix[MAX][MAX];
int v[MAX][MAX];
int ans = 1000;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
        }
    }
}

void bfs(int i, int j, int cnt){
    queue<pair<int, int>> q;
    q.push({i,j});
    v[i][j] = 1;
    matrix[i][j] = cnt;
    
    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        
        for(int dir=0; dir<4; dir++){
            int nr = r + dr[dir]; int nc = c + dc[dir];
            if(nr < 0 || nr >= N || nc < 0 || nc >=N) continue;
            if(v[nr][nc] || matrix[nr][nc] == 0) continue;
            
            q.push({nr, nc});
            v[nr][nc] = 1;
            matrix[nr][nc] = cnt;
        }
    }
    
}

int get_bridge(int cnt){
    queue<pair<int,int>> q;
    memset(v, -1, sizeof(v));
    
    // 해당 cnt인 섬들의 좌표를 모두 push
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(matrix[i][j] == cnt) {
                q.push({i,j});
                v[i][j] = 0;
            }
        }
    }
    
    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        
        for(int dir=0; dir<4; dir++){
            int nr = r + dr[dir]; int nc = c + dc[dir];
            if(nr < 0 || nr >= N || nc < 0 || nc >=N) continue;
            //if(v[nr][nc]) continue;
            
            if(matrix[nr][nc] !=0 && matrix[nr][nc] != cnt){
                return v[r][c];
            }
            
            if(matrix[nr][nc] == 0 && v[nr][nc] == -1){
                v[nr][nc] = v[r][c] + 1;
                q.push({nr,nc});
            }
        }
    }
    // 이곳에 올일은 없지만..
    return 1e9;
}


void solve(){
    int cnt = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(v[i][j] == 0 && matrix[i][j] == 1){
                bfs(i, j, cnt++);
            }
        }
    }
    
    for(int i=1; i<cnt; i++){
        //cout << endl << get_bridge(i) << endl;
        ans = min(ans, get_bridge(i));
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}
