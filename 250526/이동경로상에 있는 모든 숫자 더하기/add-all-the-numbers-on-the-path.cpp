#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

int matrix[MAX][MAX];

int dr[] = {-1, 0, 1, 0};  // 북 왼 남 오
int dc[] = {0, -1, 0, 1}; 

int main() {
    // Please write your code here.
    int N, T;
    string input;
    cin >> N >> T;
    cin >> input;

    int sum = 0;
    int dir_idx = 0;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> matrix[i][j];
        }
    }

    int r = N/2;
    int c = r;
    int move_r = r;
    int move_c = c;
    sum += matrix[r][c];

    for(int i=0;i<T; i++){
        if(input[i] == 'F'){
        
            move_r = r + dr[dir_idx];
            move_c = c + dc[dir_idx];
            if(move_r >= 0 && move_c >=0 && move_r < N && move_c < N){
                r = r + dr[dir_idx];
                c = c + dc[dir_idx];
                sum += matrix[r][c];
            }
        }
        else if(input[i] == 'L'){
            dir_idx = (dir_idx + 1) % 4;
        }
        else if (input[i] == 'R'){
            dir_idx = (dir_idx - 1 + 4) % 4;
        }

    }

    cout << sum;

    return 0;
}