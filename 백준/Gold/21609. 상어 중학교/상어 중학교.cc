#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 25
using namespace std;

int N, M;
int matrix[MAX][MAX];
int v[MAX][MAX];
int R;  // 레인보우를 편의상 2M으로 설정함.
int ans;

int tmp[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct pos{
    int i,j;
};
vector<pair<int,int>> group;
vector<pair<int,int>> del_group;

void input(){
    cin >> N >> M;
    R = 2 * M;
    memset(matrix, -1, sizeof(matrix));  // -1로 패딩.
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 0) matrix[i][j] = R;
        }
    }
}

void gravity(){
    int ci, cj;
    for(int si=1; si<N; si++){
        for(int sj=1; sj<=N; sj++){
            ci = si; cj = sj;
            
            while(0 < matrix[ci][cj] && matrix[ci+1][cj] == 0){
                int tmp = matrix[ci][cj];
                matrix[ci][cj] = matrix[ci+1][cj];
                matrix[ci+1][cj] = tmp;
                ci--;
            }
        }
    }
}


vector<pair<int,int>> bfs(){
    vector<pair<int,int>> group_max;
    memset(v, 0, sizeof(v));
    pair<int,int> tmp;
    int rcnt_max = 0;
    
    for(int i=1; i<=N; i++){
        for(int j=1;j<=N; j++){
            if(v[i][j] == 1) continue;
            if(matrix[i][j] < 1 || matrix[i][j] == R) continue;
            // 미방문, 일반 블록인 경우 bfs.
            
            queue<pos> q;
            vector<pair<int,int>> group;
            int color = matrix[i][j];
            int rcnt = 0;
            v[i][j] = 1;
            q.push({i,j}); group.push_back({i,j});
            
            while(!q.empty()){
                pos cur = q.front();
                q.pop();
                
                for(int dir=0; dir<4; dir++){
                    int nr = cur.i + dr[dir]; int nc = cur.j + dc[dir];
                    tmp = {nr,nc};
                    if(v[nr][nc] == 1) continue;
                    if(find(group.begin(), group.end(), tmp) != group.end()) continue;
                    
                    if(matrix[nr][nc] == color || matrix[nr][nc] == R){
                        q.push({nr,nc});
                        group.push_back({nr,nc});
                        v[nr][nc] = 1;
                        
                        if(matrix[nr][nc] == R) { v[nr][nc] = 0; rcnt++;}
                    }
                }
            }
            
            if(group_max.size() < group.size() || ( group_max.size() == group.size() && rcnt_max <= rcnt) ) {
                group_max = group;
                rcnt_max = rcnt;
            }
            group.clear();

        }
    }
    
    return group_max;
}


void solve(){
    
    while(1){
        // [1] 크기가 가장 큰 블록그룹 찾기.
        // 무조건 미방문 일반 색상일때만 bfs하는 걸로 하자.
        del_group = bfs();
        if(del_group.size() < 2) break;
        
        ans += del_group.size() * del_group.size();
        
        // [2] 해당 그룹 블록 clear
        for(auto cur : del_group){
            matrix[cur.first][cur.second] = 0;
        }
        
        // [3] 첫번째 중력 작용
        gravity();
        
        // [4] 90도 반시계 회전
        memset(tmp, 0, sizeof(tmp));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                tmp[1 + i][1 + j] = matrix[1 + j][1 + N - 1 - i];
            }
        }
        memset(matrix, -1, sizeof(matrix));
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                matrix[i][j] = tmp[i][j];
            }
        }
        
        // [5] 마지막 두번째 중력 작용
        gravity();
        
    }
    cout << ans <<"\n";
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}
