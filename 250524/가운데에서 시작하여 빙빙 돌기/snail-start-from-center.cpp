#include <iostream>
#define MAX 101
using namespace std;

int matrix[MAX][MAX];

int dr[] = {0, -1, 0, 1};  // 오 위 왼 아
int dc[] = {1, 0, -1, 0};

int main() {
    // Please write your code here.
    int cnt = 1;
    int N;
    cin >> N;

    int r = N/2 + 1;
    int c = r;
    int dir = 0;
    int move_r; 
    int move_c;

    int dir_flag = 0;
    int dir_cnt = 1;
    int flag = 0;

    
    for(int i=1; i<= N*N; i++){
        matrix[r][c] = cnt++;

        move_r = r + dr[dir];
        move_c = c + dc[dir];

        if((move_r < 1 || move_c < 1 || move_r > N || move_c > N) || dir_flag == dir_cnt) {
            dir = (dir + 1) % 4;
            dir_flag = 0;
            flag++; // 1
            if(flag >= 2) {
                dir_cnt++; // 2
                flag = 0;
            }
        }
        dir_flag++;

        r = r + dr[dir];
        c = c + dc[dir];
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}