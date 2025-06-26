#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;

int N, M;
int matrix[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(int r, int c){
    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    matrix[r][c] = 2;  // 방문이면 2, 막힌 곳이면 1, 방문하지 않은 빈 곳 0
    int move_r, move_c;
    
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            move_r = front.first + dr[i];
            move_c = front.second + dc[i];
            
            if(move_r >= N) move_r -=N;
            if(move_r < 0) move_r += N;
            
            if(move_c >= M) move_c -= M;
            if(move_c < 0) move_c += M;
                        
            if(matrix[move_r][move_c] == 0){
                matrix[move_r][move_c] = 2;
                q.push(make_pair(move_r, move_c));
            }
        }
        
    }
}

int main(void){
    cin >> N >> M;
    int cnt = 0;
    
    for(int i=0;i<N; i++){
        for(int j=0;j<M; j++){
            cin >> matrix[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix[i][j] == 0) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    
}