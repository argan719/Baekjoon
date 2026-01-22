#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 101
using namespace std;

int N,M;
int matrix[MAX][MAX];
int v[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int bfs(){
    queue<pair<int, int>> q;
    int nr, nc;
    q.push(make_pair(0,0));
    v[0][0] = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        // 정답처리는 이곳에서
        if(cur.first == N-1 && cur.second == M-1) return v[cur.first][cur.second];
        
        for(int i=0; i<4; i++){
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >=M) continue;
            if(v[nr][nc] || !matrix[nr][nc]) continue;
            
            q.push(make_pair(nr, nc));
            v[nr][nc] = v[cur.first][cur.second] + 1;  // 전 칸으로부터 왔으므로 이게 곧 정답 역할.
        }
    }
    return -1;
}

int main(){
    cin >> N >> M;
    string input;
    
    // 0 ~ N-1, M-1 로 만듦.
    for(int i=0;i<N; i++){
        cin >> input;
        for(int j=0; j<M; j++){
            matrix[i][j] = input[j] - '0';
        }
    }
    
    cout << bfs();
    
    return 0;
}
