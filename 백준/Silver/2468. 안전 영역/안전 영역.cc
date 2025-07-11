#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX 101
using namespace std;

int N;
int matrix[MAX][MAX];
int visited[MAX][MAX];
int max_value = 0;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(int height, int r, int c){
    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    visited[r][c] = 1;
    int nr, nc;
    
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            
            if(nr < 0 || nc < 0 || nr >=N || nc >= N) continue;
            if(visited[nr][nc]) continue;
            if(matrix[nr][nc] <= height) continue; // 조건추가
            
            q.push(make_pair(nr, nc));
            visited[nr][nc] = 1;
        }
        
    }
    
}

int main(void){
    cin >> N;
    int cnt = 0;
    int result = 1;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
            if(max_value < matrix[i][j]) max_value = matrix[i][j];
        }
    }
    
    for(int height = max_value-1; height >=1; height--){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(matrix[i][j] > height && !visited[i][j]) {
                    bfs(height, i, j);
                    cnt++;
                } 
            }
        }
        if(result < cnt) result = cnt;
        cnt = 0;
        for(int i=0; i<N; i++){
            memset(visited[i], 0, sizeof(int)*N);
        }
    }
    
    cout << result;
}