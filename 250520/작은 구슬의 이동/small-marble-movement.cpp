#include <iostream>
#define MAX 51
using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};  // 좌 상 하 우

int matrix[MAX][MAX];

int main() {
    // Please write your code here.
    int N, T;
    cin >> N >> T;

    int R, C;
    char D;
    cin >> R >> C >> D;
    // U 위 D 아래 R 오른쪽 L 왼쪽

    int dir=0;

    if(D == 'U'){
        dir = 1;
    }
    else if(D == 'D'){
        dir = 2;
    }
    else if(D == 'R'){
        dir = 3;
    }
    else{
        dir = 0;
    }

    for(int i=0; i<T; i++){
        C += dx[dir];
        R += dy[dir];

        if(R < 1 || C < 1 || R > N || C > N){
            dir = 3 - dir;
            C += dx[dir];
            R += dy[dir];
        }

    }

    cout << R << " " << C;



    return 0;
}