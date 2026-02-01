#include<iostream>
#include<cstring>
#define MAX 1001
using namespace std;

int matrix[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
// 상 0
// 하 1
// 좌 2
// 우 3

int M, n;
int flag = 1;
int r,c;

int solve(string command, int d){
    int nr = 0, nc =0;
    if(command == "MOVE"){
        for(int i=0; i<d; i++){
            nr = r + dr[flag];
            nc = c + dc[flag];
            
            if(nr < 0 || nr > M || nc < 0 || nc > M) return -1;
            r = nr;
            c = nc;
        }
        
    }
    else if(command == "TURN"){
        if(flag == 0){
            if(d == 0) flag = 2;
            else flag = 3;
        }
        else if(flag == 1){
            if(d == 0) flag = 3;
            else flag = 2;
        }
        else if(flag == 2){
            if(d == 0) flag = 1;
            else flag = 0;
        }
        else{
            if(d == 0) flag = 0;
            else flag = 1;
        }
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
    cout << r << " " << c << endl;
}

int main(){
    input();
    
}
