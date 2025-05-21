#include <iostream>
#define MAX 101
using namespace std;

int matrix[MAX][MAX];
// 0 1 2 3
int dr[] = {0, 1, 0, -1}; // 오른쪽 아래쪽 왼쪽 위쪽
int dc[] = {1, 0, -1, 0};

int main() {
    // Please write your code here.
    int N, M;
    cin >> N >> M;

    int cnt = 1;
    int dir = 0;

    int r = 0;
    int c = 0;

    int pr, pc;

    while(1){
        matrix[r][c] = cnt;
        cnt++;

        pr = r + dr[dir];
        pc = c + dc[dir];

        if((pr < 0 || pc < 0 || pr >= N || pc >= M) || matrix[pr][pc] != 0) {
            dir = (dir + 1) % 4;
            pr = r + dr[dir];
            pc = c + dc[dir];
        }

        if(matrix[pr][pc] != 0) break;
        r = pr;
        c = pc;
        
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }




    return 0;
}