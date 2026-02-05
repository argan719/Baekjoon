#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#define MAX 1001
using namespace std;

int R, C;
int K;
int SR, SC;

int matrix[MAX][MAX];
int m[4];

// 0 상 하 좌 우
int dr[] = {0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, -1, 1};

void input(){
    cin >> R >> C;
    cin >> K;
    
    int br, bc;
    for(int i=0; i<K; i++){
        cin >> br >> bc;
        matrix[br][bc] = 1;  // 장애물 표시
    }
    cin >> SR >> SC;
    cin >> m[0] >> m[1] >> m[2] >> m[3];
}

void solve(){
    
    int r,c;
    r = SR; c = SC;
    int nr, nc;
    
    queue<pair<int,int>> q;
    q.push(make_pair(SR,SC));
    matrix[SR][SC] = 1;
    
    while(!q.empty()){
        q.pop();
        
        for(int i=0; i<4; i++){
            nr = r + dr[m[i]];
            nc = c + dc[m[i]];
            
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(matrix[nr][nc]) continue;
            
            q.push(make_pair(nr,nc));
            matrix[nr][nc] = 1;
            r = nr;
            c = nc;
            i--;
        }
    }
    cout << r << " " << c;
    
}

int main(){
    input();
    solve();
    return 0;
}
