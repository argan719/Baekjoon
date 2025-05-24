#include <iostream>
#define MAX 101
using namespace std;

int dr[] = {1, 0, -1, 0};  // 아래 오른 위 왼
int dc[] = {0, 1, 0, -1};

int matrix[MAX][MAX];

int main() {
    // Please write your code here.
    int N, M;
    cin >> N >> M;

    int cnt = 1;
    int r = 0;
    int c = 0;

    int move_r, move_c;
    int dir = 0;

    for(int i=0;i<N*M; i++){
        matrix[r][c] = cnt++;

        move_r = r + dr[dir];
        move_c = c + dc[dir];
        if((move_r < 0 || move_c < 0 || move_r >= N || move_c >= M) || matrix[move_r][move_c] != 0){
            dir = (dir + 1) % 4;
        }

        r = r + dr[dir];
        c = c + dc[dir];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}