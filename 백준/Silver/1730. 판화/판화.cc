#include<iostream>
#include<cstring>
#define MAX 11
using namespace std;
int N;
int matrix[MAX][MAX];
string cmd;

void input(){
    cin >> N;
    cin >> cmd;
}

void solve(){
    int r = 0, c = 0;
    
    for(auto n : cmd){
        
        if(n == 'U' && r - 1 >= 0){
            matrix[r--][c] |= 1;
            matrix[r][c] |= 1;
        }
        else if(n == 'D' && r + 1 < N){
            matrix[r++][c] |= 1;
            matrix[r][c] |= 1;
        }
        else if(n == 'L' && c - 1 >= 0){
            matrix[r][c--] |= 2;
            matrix[r][c] |= 2;
        }
        else if(n == 'R' && c + 1 < N){
            matrix[r][c++] |= 2;
            matrix[r][c] |= 2;
        }
    }
    
    // 정답출력
    string ans = ".|-+";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << ans[matrix[i][j]];
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}