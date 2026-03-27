#include<iostream>
#include<cstring>
#include<vector>
#define MAX 11
using namespace std;

int N;
int matrix[MAX][MAX];
string cmd;
// 0 = '.'
// 1 = '|'
// 2 = '-'
// 3 = '+'

void input(){
    cin >> N;
    cin >> cmd;
}

int r = 1;
int c = 1;

// 상 하 좌 우
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};


void solve(){
    int nr, nc;
    for(auto cur : cmd){
        if(cur == 'U'){
            nr = r + dr[0];
            nc = c + dc[0];
            if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
            matrix[r][c] |= 1;
            matrix[nr][nc] |=1;
            r = nr; c = nc;
        }
        else if(cur == 'D'){
            nr = r + dr[1];
            nc = c + dc[1];
            if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
            matrix[r][c] |= 1;
            matrix[nr][nc] |=1;
            r = nr; c = nc;
        }
        else if(cur == 'L'){
            nr = r + dr[2];
            nc = c + dc[2];
            if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
            matrix[r][c] |= 2;
            matrix[nr][nc] |=2;
            r = nr; c = nc;
        }
        else if(cur == 'R'){
            nr = r + dr[3];
            nc = c + dc[3];
            if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
            matrix[r][c] |= 2;
            matrix[nr][nc] |=2;
            r = nr; c = nc;
        }
    }
    
    
    string output = ".|-+";
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << output[matrix[i][j]];
        }
        cout << "\n";
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}
