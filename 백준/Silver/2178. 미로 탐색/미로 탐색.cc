#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 101
using namespace std;

int N, M;
int matrix[MAX][MAX];
int visited[MAX][MAX];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int cnt;

void bfs(){
    queue<pair<int, int>> q;
    q.push(make_pair(1,1));
    int nr, nc;
    
    while(!q.empty()){
        pair<int, int> cur = q.front();  // pair로 받음.
        q.pop();
        
        if(cur.first == N && cur.second == M) {
            cout << matrix[N][M];
            return;
        }
        
        for(int i=0; i<4; i++){
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            
            if(nr < 1 || nc < 1 || nr > N || nc > M) continue;  // 범위확인
            
            if(!visited[nr][nc] && matrix[nr][nc] == 1) { // 조건확인
                visited[nr][nc] = 1;   // 방문처리
                matrix[nr][nc] = matrix[cur.first][cur.second] + 1;
                q.push(make_pair(nr, nc));
            }
        }
    }
}

int main(void){
    cin >> N >> M;
    string input;
    
    for(int i=1; i<=N; i++){
        cin >> input;
        for(int j=0; j<M; j++){
            matrix[i][j+1] = input[j] - '0';
        }
    }
    
    bfs();
}