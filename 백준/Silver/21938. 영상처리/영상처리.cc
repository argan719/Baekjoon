#include<iostream>
#define MAX 1001
using namespace std;

typedef struct color{
    int r; 
    int g;
    int b;
}Color;

int N, M;
int T;
Color input[MAX];
int matrix[MAX][MAX];
int cnt;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c){
    matrix[r][c] = 1;
    int next_r = 0;
    int next_c = 0;
    
    for(int i=0; i<4; i++){
        next_r = r + dr[i];
        next_c = c + dc[i];
        
        if(next_r < 0 || next_c < 0 || next_r >= N || next_c >= M) continue;
        if(matrix[next_r][next_c] == 255) dfs(next_r, next_c);
    }
}

int main(void){
    cin >> N >> M;
    int sum = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> input[j].r >> input[j].g >> input[j].b;
            sum += (input[j].r + input[j].g + input[j].b);
            sum = sum/3;
            matrix[i][j] = sum;
            sum = 0;
        }
    }
    cin >> T;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix[i][j] >= T) matrix[i][j] = 255;
            else matrix[i][j] = 0;
        }
    }
    
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix[i][j] == 1) continue;
            if(matrix[i][j] == 255) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    
    cout << cnt;


}