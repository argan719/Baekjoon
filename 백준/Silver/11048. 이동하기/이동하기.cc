#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 1001
using namespace std;

int matrix[MAX][MAX];
int N, M;

int dr[] = {1, 0, 1};
int dc[] = {0, 1, 1};

int ans;

void input(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> matrix[i][j];
        }
    }
}

void solve(){
    int max_val = 0;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            
            max_val = 0;
            for(int dir=0; dir<3; dir++){
                int nr = i - dr[dir]; int nc = j - dc[dir];
                if(nr < 1 || nr > N || nc < 1 || nc > M) continue;
                
                max_val = max(max_val, matrix[nr][nc]);
            }
            matrix[i][j] += max_val;
        }
    }
    
    cout << matrix[N][M];
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}