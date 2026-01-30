#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#define MAX 9
using namespace std;

vector<pair<int,int>> pos;
int matrix[MAX][MAX];
int matrix2[MAX][MAX];
int v[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int N, M;

void input(){
    int r;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> r;
            matrix[i][j] = r;
            if(r == 0) {
                pos.push_back({i, j});
            }
        }
    }
}


int bfs(){
    queue<pair<int, int>> q;
    int nr, nc;
    memset(v, 0, sizeof(v));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix2[i][j] == 2) {
                // 단위작업 - 바이러스 전부 push
                q.push(make_pair(i,j));
                v[i][j] = 1;
            }
        }
    }
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        // 연결 4방향
        for(int i=0; i<4; i++){
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            // 범위내 미방문 조건맞으면
            if(nr < 0 || nr >= N || nc < 0 || nc >=M) continue;
            if(v[nr][nc] != 0) continue;
            
            if(matrix2[nr][nc] == 0){
                matrix2[nr][nc] = 2;
                q.push(make_pair(nr, nc));
                v[nr][nc] = 1;
            }
        }
    }
    
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix2[i][j] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
    
}

int main(){
    input();
    
    int max = 0;
    int result;
    for(int i=0; i< pos.size()-2; i++){
        if(matrix[pos[i].first][pos[i].second] != 0) continue;
        for(int j=1+i; j< pos.size()-1; j++){
            if(matrix[pos[j].first][pos[j].second] != 0) continue;
            for(int k=1+j; k< pos.size(); k++){
                if(matrix[pos[k].first][pos[k].second] != 0) continue;
                
                memcpy(matrix2, matrix, sizeof(matrix));
                
                matrix2[pos[i].first][pos[i].second] = 1;
                matrix2[pos[j].first][pos[j].second] = 1;
                matrix2[pos[k].first][pos[k].second] = 1;
                
                result = bfs();
                if(max < result) max = result;
            }
        }
    }
    cout << max;
    
    return 0;
}
