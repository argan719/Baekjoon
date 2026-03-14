#include<iostream>
#define MAX 20
using namespace std;

int matrix[MAX][MAX];
int ans;
int ans_i, ans_j;
int N = 19;

// 우상 우 우하 하
int dr[] = {-1, 0, 1, 1};
int dc[] = {1, 1, 1, 0};

void input(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
        }
    }
}

void check(int r, int c, int dir){
    int nr = r; int nc = c;
    int val = matrix[r][c];
    int cnt = 1; // 본인 포함.
    
    while(1){
        nr += dr[dir]; nc += dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N) break;
        if(matrix[nr][nc] != val) break;
        
        cnt++;
    }
    if(cnt == 5) {
        cout << val << "\n";
        cout << r+1 << " " << c+1 << "\n";
        exit(0);
    }
}

void solve(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(matrix[i][j] == 0) continue;
            
            for(int dir=0; dir<4; dir++){
                int nr =  i - dr[dir]; int nc = j - dc[dir];
                if(matrix[nr][nc] == matrix[i][j]) continue;
                
                check(i, j, dir);
            }
            
        }
    }
    // 승부가 나지 않은 경우
    cout << 0 << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}