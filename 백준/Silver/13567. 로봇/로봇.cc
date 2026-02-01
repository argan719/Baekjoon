#include<iostream>
#include<cstring>
#define MAX 1001
using namespace std;

int matrix[MAX][MAX];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
// 상 0
// 하 1
// 좌 2
// 우 3

int M, n;
int flag = 1; // 초기 방향 동쪽.
int r,c;

int solve(string cmd, int d){
    if(cmd == "MOVE"){
        r = r + dr[flag] * d;
        c = c + dc[flag] * d;
        
        if(r < 0 || r > M || c < 0 || c > M) return -1;
    }
    else if(cmd == "TURN"){
        if(d == 0) flag = (flag + 1)%4;
        else if(d == 1) flag = (flag + 3)%4;
    }
    return 1;
}

void input(){
    string command;
    int val;
    
    cin >> M >> n;
    for(int i=0; i<n; i++){
        cin >> command >> val;
        if(solve(command,val) == -1) {
            cout << -1 << endl;
            return;
        }
    }
    cout << c << " " << r << endl;
}

int main(){
    input();
    
}