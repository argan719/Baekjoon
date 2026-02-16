#include<iostream>
#include<cstring>
#include<vector>
#define MAX 1000
using namespace std;

int matrix[MAX][MAX];
int N;
int target;
int target_r, target_c;
// 하 우 상 좌
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void input(){
    cin >> N;
    cin >> target;
}

void solve(){
    int r = 0, c = 0, nr, nc;  // 시작 (1의) 좌표
    int flag = 0;
    
    for(int val = N*N; val >= 1; val--){
        matrix[r][c] = val;
        
        if(val == target) {
            target_r = r + 1, target_c = c + 1;
        }
        
        nr = r + dr[flag], nc = c  + dc[flag];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N || matrix[nr][nc] != 0){
            flag = (flag + 1) % 4;
            nr = r + dr[flag], nc = c + dc[flag];
        }
        r = nr, c = nc;
    }
    
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << target_r << " " << target_c << endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    input();
    solve();
}