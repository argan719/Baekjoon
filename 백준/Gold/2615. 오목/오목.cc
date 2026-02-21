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
            
            // 중복 방지 조건 추가 (첫번째 오목이 아님을 감지 - 6개 이상 막기 위함)
            if(matrix[i][j-1] == matrix[i][j]) continue;
            
            r = i, c = j, cnt = 1;
            while(c <= N){
                if(matrix[r][++c] == matrix[i][j]) cnt++;
                else break;
            }
            if(cnt == 5) {
                cout << matrix[i][j] << "\n" << i << " " << j << "\n";
                return;
            }
        }
    }
    
    // 세로 방향
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(matrix[i][j] == 0) continue;
            
            // 중복 방지 조건 추가 (첫번째 오목이 아님을 감지 - 6개 이상 막기 위함)
            if(matrix[i-1][j] == matrix[i][j]) continue;
            
            r = i, c = j, cnt = 1;
            while(r <= N){
                if(matrix[++r][c] == matrix[i][j]) cnt++;
                else break;
            }
            if(cnt == 5) {
                cout << matrix[i][j] << "\n" << i << " " << j << "\n";
                return;
            }
        }
    }
    
    // 오른쪽 대각선 방향
    for(int i=1; i<=N; i++){
        for(int j=1; j<= N; j++){
            if(matrix[i][j] == 0) continue;
            
            // 중복 방지 조건 추가 (첫번째 오목이 아님을 감지 - 6개 이상 막기 위함)
            if(matrix[i-1][j-1] == matrix[i][j]) continue;
            
            r = i, c = j, cnt = 1;
            while(c <= N){
                if(matrix[++r][++c] == matrix[i][j]) cnt++;
                else break;
            }
            if(cnt == 5) {
                cout << matrix[i][j] << "\n" << i << " " << j << "\n";
                return;
            }
            
        }
    }
    
    // 왼쪽 대각선 방향 (맨 왼쪽이므로 다른 방향과 달리 맨 마지막 오목의 좌표를 출력해야함!)
    for(int i=1; i<=N; i++){
        for(int j=5; j<= N; j++){
            if(matrix[i][j] == 0) continue;
            
            // 중복 방지 조건 추가 (첫번째 오목이 아님을 감지 - 6개 이상 막기 위함)
            if(matrix[i-1][j+1] == matrix[i][j]) continue;
            
            r = i, c = j, cnt = 1;
            while(c >= 1 && r <= N){
                if(matrix[++r][--c] == matrix[i][j]) cnt++;
                else break;
            }
            if(cnt == 5) {
                cout << matrix[--r][++c] << "\n" << r << " " << c << "\n";
                return;
            }
        
        }
    }
    
    // 무승부인 경우
    cout << 0 << endl;
}

int main(){
    input();
    solve();
}