#include<iostream>
using namespace std;

int matrix[101][101];
int N, M;
int main(void){
    cin >> N >> M;
    int cnt = 0;
    int x1, y1, x2, y2;
    for(int i=0; i<N; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int r=x1; r<=x2; r++){
            for(int c=y1; c<=y2; c++){
                matrix[r][c]++;
            }
        }
    }
    
    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            if(matrix[i][j] > M) cnt++;
        }
    }
    cout << cnt;
}