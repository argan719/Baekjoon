#include <iostream>
#include <cstring>
#define MAX 1001
using namespace std;

int matrix[MAX][MAX];

int dr[] = {-1, 0, 1, 0}; // 위 오른 아래 왼
int dc[] = {0, 1, 0, -1};

int main() {
    // Please write your code here.
    int N;
    int K;
    int dir;
    int r,c;
    string input;
    int cnt = 0;

    cin >> N;
    // 왼쪽 / 이면 -1
    // 오른쪽 |이면 1
    for(int i=1;i<=N;i++){
        cin >> input;
        for(int j=0; j<N;j++){
            if(input[j] == '/') matrix[i][j+1] = -1;  // 왼쪽
            else matrix[i][j+1] = 1;  // 오른쪽
        }
    }

    // for(int i=1; i<=N;i++){
    //     for(int j=1; j<=N;j++){
    //         cout << matrix[i][j];
    //     }
    //     cout << endl;
    // }

    cin >> K;

    // 위에서 들어오는 경우
    if(K/N == 0 || (K/N == 1 && K%N == 0)) {
        dir = 0;

        r = 1;
        c = K;
    }  // 오른쪽에서 들어오는 경우
    else if(K/N == 1 || (K/N == 2 && K%N == 0)){
        dir = 1;

        if(K%N == 0) r = N;
        else r = K % N;
        c = N;
    } // 아래에서 들어오는 경우
    else if(K/N == 2 || (K/N == 3 && K%N == 0)){
        dir = 2;

        r = N;
        if(K%N == 0) c = 1;
        else c = N+1 - (K % N);
    }  // 왼쪽에서 들어오는 경우
    else{
        dir = 3;

        c = 1;
        if(K % N == 0) r = 1;
        r = N+1 - (K % N);
    }

    //cout << "결정된 dir : " << dir << endl;


    while((r >= 1 && c >= 1 && r <= N && c <= N)){

        if(matrix[r][c] == -1){  // 거울 왼쪽인데
            if(dir == 0){  // 위에서 들어오면
                dir = 3;  // 왼쪽으로 가야 함.
            }
            else if(dir == 1){  // 오른쪽에서 들어오면
                dir = 2;  // 아래로 가야함
            }
            else if(dir == 2){ // 아래에서 들어오면
                dir = 1;  // 오른쪽으로 가야함
            }
            else {  // 왼쪽에서 들어오면
                dir = 0;  // 위로 가야함
            }
        }
        else{  // 거울 오른쪽인데
            if(dir == 0){  // 위에서 들어오면
                dir = 1;  // 오른쪽으로 가야 함
            }
            else if(dir == 1){  // 오른쪽에서 들어오면
                dir = 0;  // 위로 가야 함
            }
            else if(dir == 2){  // 아래에서 들어오면
                dir = 3;  // 왼쪽으로 가야함
            }
            else{   // 왼쪽에서 들어오면
                dir = 2; // 아래쪽으로 가야 함
            }
        }

        r = r + dr[dir];
        c = c + dc[dir];

        if(dir == 3) dir = 1;
        else if(dir == 1) dir = 3;
        else if(dir == 2) dir = 0;
        else dir = 2;

        // 오른쪽 -> 왼쪽
        // 왼쪽 -> 오른쪽
        // 아래 -> 위
        // 위 -> 아래

        
        cnt++;
    }
    
    cout << cnt;

    return 0;
}