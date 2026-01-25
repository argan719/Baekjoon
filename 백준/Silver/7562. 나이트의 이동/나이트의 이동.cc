#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 301
using namespace std;

vector<int> ans;
//int matrix[MAX][MAX];
int v[MAX][MAX];

int T;
int N;
int sr,sc, er,ec;  // sr,sc에서 출발하여 er,ec에 도착

int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int bfs(){
    queue<pair<int,int>> q;
    int nr, nc;
    q.push(make_pair(sr, sc));
    v[sr][sc] = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        // 정답처리는 이곳에서
        if(cur.first == er && cur.second == ec) return v[cur.first][cur.second]-1;
        // 8방향 연결
        for(int i=0; i<8; i++){
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            
            if(nr < 0 || nr >=N || nc < 0 || nc >= N) continue;
            if(v[nr][nc] !=0) continue;
            
            // 범위내 미방문 조건 맞으면 단위작업
            q.push(make_pair(nr,nc));
            v[nr][nc] = v[cur.first][cur.second] + 1;
        }
    }
    return -1;
}

int main(){
    cin >> T;
    
    for(int t=0; t<T; t++){
        cin >> N;
        cin >> sr >> sc;
        cin >> er >> ec;
        ans.push_back(bfs());
        for(int i=0; i<N; i++) memset(v[i], 0, sizeof(int)*N);
    }
    
    for(auto n : ans){
        cout << n << "\n";
    }
    return 0;
}
