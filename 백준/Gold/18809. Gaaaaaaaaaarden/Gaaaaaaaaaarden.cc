#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<climits>
#define MAX 51
#define RED 10
#define GREEN 20
#define FLOWER INT_MIN
using namespace std;

int matrix[MAX][MAX];
int N, M, R, G;
//int v[MAX][MAX];

struct pos{
    int x, y;
};
vector<int> yellow;  // 배양액을 뿌릴 수 있는 땅
int ans;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void input(){
    cin >> N >> M >> G >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 2) yellow.push_back(i*M + j);
        }
    }
}

int count(){
    queue<pos> q;
    int cnt = 0;
    int tmp[MAX][MAX];
    int v[MAX][MAX];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            tmp[i][j] = matrix[i][j];
            v[i][j] = INT_MAX;
            if(matrix[i][j] == RED || matrix[i][j] == GREEN) {
                // 단위작업
                q.push({i,j});
                v[i][j] = 1;
            }
        }
    }

    while(!q.empty()){
        int len = q.size();
        
        for(int i=0; i<len; i++){
            auto [r,c] = q.front();
            q.pop();
            int color = tmp[r][c];
            if(color == 1 || color == 0) continue;
            
            // 연결 상하좌우
            for(int dir=0; dir<4; dir++){
                int nr = r + dr[dir], nc = c + dc[dir];
                // 범위내 미방문(카운트) 조건 맞으면
                if(nr < 0 || nr >= N || nc < 0 || nc >=M) continue;
                // 미방문
                if(v[nr][nc] < v[r][c] + 1) continue;
                // 조건(호수 아님) 맞으면
                if(tmp[nr][nc] == 0) continue;
                            
                // 꽃이 피어나는 상황
                if(v[nr][nc] == v[r][c] + 1 && ((tmp[nr][nc] == RED && color == GREEN) || (tmp[nr][nc] == GREEN && color == RED) )) {
                    cnt++; tmp[nr][nc] = 0; continue;
                }
                
                if(v[nr][nc] > v[r][c] + 1) {
                    q.push({nr,nc});
                    tmp[nr][nc] = color;
                    v[nr][nc] = v[r][c] + 1;
                }
                
            }
        }
        
    }
    return cnt;
}
//int dfs_cnt = 0;
void dfs(int n, int rcnt, int gcnt){
    // 가지치기 필요
    if(rcnt > R || gcnt > G) return;

    // 종료조건은 이곳에서
    if(n == yellow.size()){
        // 꽃의 개수를 카운트하는 bfs
        // 정답처리
        if(rcnt == R && gcnt == G) {
            int cnt = count();
            if(ans < cnt) ans = cnt;
        }
        return;
    }
    
    // 해당 땅에 뿌리지 않는 경우
    dfs(n+1, rcnt, gcnt);
    // 해당 땅에 빨간색 배양액 뿌리는 경우
    matrix[yellow[n]/M][yellow[n]%M] = RED;
    dfs(n+1, rcnt+1, gcnt);
    matrix[yellow[n]/M][yellow[n]%M] = 2;
    // 해당 땅에 초록색 배양액 뿌리는 경우
    matrix[yellow[n]/M][yellow[n]%M] = GREEN;
    dfs(n+1, rcnt, gcnt+1);
    matrix[yellow[n]/M][yellow[n]%M] = 2;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0, 0);
    cout << ans;
}