#include<iostream>
#define MAX 101
using namespace std;

int matrix[MAX][MAX];
int N;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int main(void){
    cin >> N;
    int x, y;
    int nr, nc;
    int cnt = 0;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        
        for(int r=x; r < x+ 10; r++){
            for(int c=y; c < y + 10; c++){
                matrix[r][c] = 1;
            }
        }
    }
    
    for(int i=1; i<=99; i++){
        for(int j=1; j<= 99; j++){
            if(matrix[i][j] == 0) continue;
            
            for(int k=0;k<4; k++){
                nr = i + dr[k];
                nc = j + dc[k];
                if(matrix[nr][nc] == 0) cnt++;
            }
        }
    }
    cout << cnt;
    
}