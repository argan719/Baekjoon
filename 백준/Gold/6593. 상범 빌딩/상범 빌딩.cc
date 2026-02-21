#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 31
using namespace std;

struct pos{
    int l, r, c;
};

int L, N, M;
pos start, escape;

int matrix[MAX][MAX][MAX];
int v[MAX][MAX][MAX];

int dl[] = {0, 0, 0, 0, -1, 1};
int dr[] = {0, 0, 1, -1, 0, 0};
int dc[] = {1, -1, 0, 0, 0, 0};

void input(){
    string arr;
    for(int i=0; i<L; i++){
        for(int j=0; j<N; j++){
            cin >> arr;
            for(int k=0; k<M; k++){
                if(arr[k] == 'S') { start = {i,j,k}; matrix[i][j][k] = 1;}  // 갈수있기에 1
                else if(arr[k] == 'E') { escape = {i,j,k}; matrix[i][j][k] = 1;} // 갈수있기에 1
                else if(arr[k] == '.') matrix[i][j][k] = 1;  // 갈 수 있는 곳 1
                else matrix[i][j][k] = 0;  // 갈 수 없는 곳 0
            }
        }
    }

}

int solve(){
    memset(v, 0, sizeof(v));
    queue<pos> q;
    q.push(start);
    v[start.l][start.r][start.c] = 1;
    
    while(!q.empty()){
        pos cur = q.front();
        q.pop();
        
        // 정답처리는 이곳에서
        if(cur.l == escape.l && cur.r == escape.r && cur.c == escape.c) return v[cur.l][cur.r][cur.c] - 1;
        
        for(int dir=0; dir<6; dir++){
            int nl = cur.l + dl[dir];
            int nr = cur.r + dr[dir];
            int nc = cur.c + dc[dir];
            
            // 범위내 미방문 조건(1이면) 맞으면
            if(nl < 0 || nl >= L || nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(v[nl][nr][nc] !=0 || matrix[nl][nr][nc] == 0) continue;
            
            // 단위작업
            q.push({nl, nr, nc});
            v[nl][nr][nc] = v[cur.l][cur.r][cur.c] + 1;
        }
    }
    
    return -1;
}

int main(){
    while(true){
        cin >> L >> N >> M;
        if(L == 0 && N == 0 && M == 0) break;
        input();
        int r = solve();
        if(r == -1) cout << "Trapped!" << "\n";
        else cout << "Escaped in " << r << " minute(s)." << "\n";
    }
}