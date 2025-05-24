#include <iostream>
#include <cstdlib>
#define MAX 101
using namespace std;

char matrix[MAX][MAX];

int dr[] = {0, 1, 0, -1};  // 오른 아래 왼 위
int dc[] = {1, 0, -1, 0};  

int main() {
    // Please write your code here.
    int N, M;
    cin >> N >> M;

    char val = 'A';
    int r = 0;
    int c = 0;

    int move_r, move_c;
    int dir;

    for(int i=0;i<N*M; i++){
        matrix[r][c] = val++;
        if(val >= 91) val = 65;

        move_r = r + dr[dir];
        move_c = c + dc[dir];
        if((move_r < 0 || move_c < 0 || move_r >= N || move_c >= M) || matrix[move_r][move_c] != '\0') {
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