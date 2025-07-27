// 크기 10으로 고정
// x, y 맨 왼쪽 맨 아래 좌표

#include<iostream>
#define MAX 101
using namespace std;

int matrix[MAX][MAX];
int main(void){
    int N;
    int cnt = 0;
    int x, y;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        
        for(int r=x; r< x+10; r++){
            for(int c=y; c<y+10; c++){
                matrix[r][c] = 1;
            }
        }
    }
    
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(matrix[i][j]) cnt++;
        }
    }
    cout << cnt;
}