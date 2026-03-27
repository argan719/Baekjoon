#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#define MAX 9
using namespace std;

vector<pair<int,int>> pos;
vector<pair<int,int>> virus;
int matrix[MAX][MAX];
//int matrix2[MAX][MAX];
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
            
            if(r == 0) pos.push_back({i, j}); // 빈칸 리스트
            else if(r == 2) virus.push_back({i, j}); // 바이러스 리스트
        }
    }
}


int bfs(){
    queue<pair<int, int>> q;
    int nr, nc;
    memset(v, 0, sizeof(v));
    
//    for(int i=0; i<N; i++){
//        for(int j=0; j<M; j++){
//            if(matrix2[i][j] == 2) {
//                // 단위작업 - 바이러스 전부 push
//                q.push(make_pair(i,j));
//                v[i][j] = 1;
//            }
//        }
//    }
    // 단위작업 - 바이러스 전부 push
    for(auto cur : virus){
        q.push(cur);
        v[cur.first][cur.second] = 1;
    }
    
    
    int cnt = pos.size() - 3;  // 현재 (벽을 3개 세우고 난뒤) 빈칸 수
    
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
            
            if(matrix[nr][nc] == 0){
                //matrix[nr][nc] = 2;
                q.push(make_pair(nr, nc));
                v[nr][nc] = 1;
                cnt--; // 감염되어 빈칸 사라짐.
            }
        }
    }
    
    // 벽을 3개 세운 뒤, 바이러스 퍼진 뒤, 남아있는 빈칸의 개수
//    int cnt = 0;
//    for(int i=0; i<N; i++){
//        for(int j=0; j<M; j++){
//            if(matrix[i][j] == 0) {
//                cnt++;
//            }
//        }
//    }
    // 이중 루프 돌 필요 없이
    return cnt;
    
}

int main(){
    input();
    
    int max = 0;
    int result;
    
    for(int i=0; i< pos.size()-2; i++){
        for(int j=i+1; j< pos.size()-1; j++){
            for(int k=j+1; k< pos.size(); k++){
                
                //memcpy(matrix2, matrix, sizeof(matrix));
                
                matrix[pos[i].first][pos[i].second] = 1; // 벽 세움1
                matrix[pos[j].first][pos[j].second] = 1; // 벽 세움2
                matrix[pos[k].first][pos[k].second] = 1; // 벽 세움3
                
                result = bfs();
                if(max < result) max = result;
                
                matrix[pos[k].first][pos[k].second] = 0; // 벽 세움3 원상복수
            }
            matrix[pos[j].first][pos[j].second] = 0; // 벽 세움2 원상복구
        }
        matrix[pos[i].first][pos[i].second] = 0; // 벽 세움1 원상복구
    }
    cout << max << endl;
    
    return 0;
}