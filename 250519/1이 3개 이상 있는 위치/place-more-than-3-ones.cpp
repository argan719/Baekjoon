#include <iostream>
#define MAX 101
using namespace std;

int matrix[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    int cnt = 0;  // 인접한 칸 수
    int sum = 0;  // 전체 칸 수

    for(int i=0; i<N;i++){
        for(int j=0;j<N;j++){
            cin >> matrix[i][j];
        }
    }

    int x, y;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cnt = 0;
            for(int k=0;k<4; k++){
                x = i + dx[k];
                y = j + dy[k];
                if(x >= 0 && y >= 0 && x < N && y < N){
                    if(matrix[x][y]) cnt++;
                }
            }
            if(cnt >= 3) sum++;
        }
    }

    cout << sum;
    return 0;
}