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
    int val = N * N;  // 시작 숫자 좌표 출력시 +1해서 출력해야함 유의.
    int r = 0, c = 0;  // 시작 (1의) 좌표
    int nr, nc;
    
    if(val == target) {
        target_r = r + 1;
        target_c = c + 1;
    }
    matrix[r][c] = val--;
    
    while(val >= 1){
        
        for(int i=0; i<4; i++){
            nr = r + dr[i];
            nc = c + dc[i];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(matrix[nr][nc] != 0) continue;
            if(val == target) {
                target_r = nr + 1;
                target_c = nc + 1;
            }
            matrix[nr][nc] = val--;
            i--;
            r = nr; c = nc;
            if(val <= 0) break;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << target_r << " " << target_c << endl;
    
}

int main(){
    input();
    solve();
}