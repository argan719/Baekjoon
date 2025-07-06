#include<iostream>
#include<cstring>
#define MAX 11
using namespace std;

int N;
string order;
int matrix[MAX][MAX];
// 0, 1, 2, 3
// . | - +
int main(void){
    cin >> N;
    cin >> order;
    int r = 0;
    int c = 0;
    // 판화 기계는 작동 도중 로봇 팔이 격자 바깥으로 나가도록 하는 움직임 명령을 만나면, 무시하고 그 다음 명령을 진행한다.
    for(int i=0; i<order.size(); i++){
        //if(r < 0 || c < 0 || r >= N || c >= N) continue;
        
        if(order[i] == 'U' && (r-1 >= 0)){
            matrix[r--][c] |= 1;
            matrix[r][c] |= 1;
        }
        else if(order[i] == 'D' && (r+1 < N)){
            matrix[r++][c] |= 1;
            matrix[r][c] |= 1;
        }
        else if(order[i] == 'L' && (c-1 >= 0)){
            matrix[r][c--] |= 2;
            matrix[r][c] |= 2;
        }
        else if(order[i] == 'R' && (c+1 < N)){
            matrix[r][c++] |= 2;
            matrix[r][c] |= 2;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(matrix[i][j] == 0) cout << ".";
            else if(matrix[i][j] == 1) cout << "|";
            else if(matrix[i][j] == 2) cout << "-";
            else cout << "+";
        }
        cout << "\n";
    }
}
