#include<iostream>
#include<algorithm>
#define MAX 20
#define N 19
using namespace std;

int matrix[MAX][MAX];

void input(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> matrix[i][j];
        }
    }
}

void solve(){
    int r, c;
    int cnt = 0;
    int save_i, save_j;
    
    // 가로 방향
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(matrix[i][j] == 0) continue;
            // 중복 방지 조건 추가
            if(matrix[i][j-1] == matrix[i][j]) continue;
             
                save_i = i, save_j = j;
                r = i, c = j, cnt = 1;
                while(c <= N){
                    if(matrix[r][++c] == matrix[i][j]) cnt++;
                    else break;
                }
                if(cnt == 5) {
                    cout << matrix[save_i][save_j] << "\n" << save_i << " " << save_j << "\n";
                    return;
                }
            
            
        }
    }
    
    // 세로 방향
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(matrix[i][j] == 0) continue;
            
            if(matrix[i-1][j] == matrix[i][j]) continue;
            
            
            
                save_i = i, save_j = j;
                r = i, c = j, cnt = 1;
                while(r <= N){
                    if(matrix[++r][c] == matrix[i][j]) cnt++;
                    else break;
                }
                if(cnt == 5) {
                    cout << matrix[save_i][save_j] << "\n" << save_i << " " << save_j << "\n";
                    return;
                }
            
            
            
        }
    }
    
    // 오른쪽 대각선 방향
    for(int i=1; i<=N; i++){
        for(int j=1; j<= N; j++){
            if(matrix[i][j] == 0) continue;
            
            if(matrix[i-1][j-1] == matrix[i][j]) continue;
            
                save_i = i, save_j = j;
                r = i, c = j, cnt = 1;
                while(c <= N){
                    if(matrix[++r][++c] == matrix[i][j]) cnt++;
                    else break;
                }
                if(cnt == 5) {
                    cout << matrix[save_i][save_j] << "\n" << save_i << " " << save_j << "\n";
                    return;
                }
            
            
        }
    }
    
    // 왼쪽 대각선 방향
    for(int i=1; i<=N; i++){
        for(int j=5; j<= N; j++){
            if(matrix[i][j] == 0) continue;
            
            if(matrix[i-1][j+1] == matrix[i][j]) continue;
            
                save_i = i, save_j = j;
                r = i, c = j, cnt = 1;
                while(c >= 1 && r <= N){
                    if(matrix[++r][--c] == matrix[i][j]) { cnt++; save_i = r; save_j = c;}
                    else break;
                }
                if(cnt == 5) {
                    cout << matrix[save_i][save_j] << "\n" << save_i << " " << save_j << "\n";
                    return;
                }
            
            
        }
    }
    
    cout << 0 << endl;
    
}

int main(){
    input();
    solve();
}
