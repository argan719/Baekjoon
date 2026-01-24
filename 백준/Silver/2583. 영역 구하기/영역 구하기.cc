#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#define MAX 101
using namespace std;

int matrix[MAX][MAX];
int R, C, K;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int bfs(int r, int c){
    int cnt = 0;
    int nr, nc;
    queue<pair<int, int>> q;
    // 단위작업
    q.push(make_pair(r,c));
    matrix[r][c] = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        cnt++;
        
        for(int i=0; i<4; i++){
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(matrix[nr][nc]) continue;
            
            // 조건 맞으면 단위작업
            q.push(make_pair(nr,nc));
            matrix[nr][nc] = 1;
        }
    }
    return cnt;
}

int main(){
    cin >> R >> C >> K;
    int sr, sc, er, ec;
    
    for(int i=0; i<K; i++){
        cin >> sc >> sr >> ec >> er;
        
        for(int r = sr; r < er; r++){
            for(int c = sc ; c < ec; c++){
                matrix[r][c] = 1;
            }
        }
    }
    
    vector<int> result;
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(matrix[i][j] == 0) result.push_back(bfs(i,j));
        }
    }
    
    cout << result.size() << endl;
    sort(result.begin(), result.end());
    for(auto cur: result){
        cout << cur << " " ;
    }
    return 0;
}
