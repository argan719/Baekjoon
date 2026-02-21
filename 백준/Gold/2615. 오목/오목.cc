#include<iostream>
#define N 19
#define MAX 21
using namespace std;

int matrix[MAX][MAX];

// 우, 하, 우하(왼쪽대각선), 우상(오른쪽대각선)
int dr[] = {0, 1, 1, -1};
int dc[] = {1, 0, 1, 1};

void input(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> matrix[i][j];
        }
    }
}

void solve(){
    int val;
    int cnt;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            
            if(matrix[i][j] == 0) continue;
            val = matrix[i][j];
            
            for(int dir=0; dir<4; dir++){
                int nr = i + dr[dir];
                int nc = j + dc[dir];
                
                cnt = 1;
                while(nr >= 1 && nr <= N && nc >= 1 && nc <= N && matrix[nr][nc] == val){
                    cnt++;
                    nr = nr + dr[dir];
                    nc = nc + dc[dir];
                }
                if(cnt == 5){
                    int pr = i - dr[dir];
                    int pc = j - dc[dir];
                    
                    if(pr >= 1 && pr <= N && pc >=1 && pc <=N && val == matrix[pr][pc]) continue;
                    cout << val << "\n" << i << " " << j << "\n";
                    return;
                }
            }
        }
    }
    // 무승부인 경우!
    cout << 0 << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
}
