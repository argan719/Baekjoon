#include <iostream>
#define MAX 201
using namespace std;

int x1[10];
int x2[10];
int y1[10];
int y2[10];

int matrix[MAX][MAX];

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x1[i] += 100;
        y1[i] += 100;
        x2[i] += 100;
        y2[i] += 100;

        for(int x=x1[i]; x<x2[i]; x++){
            for(int y=y1[i]; y<y2[i]; y++){
                if(i%2 == 0) matrix[x][y] = 1;  // 빨간색
                else matrix[x][y] = 2;  // 파란색
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(matrix[i][j] == 2) cnt++;
        }
    }

    cout << cnt;


    return 0;
}