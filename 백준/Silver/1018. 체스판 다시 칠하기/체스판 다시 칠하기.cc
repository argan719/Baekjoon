#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 51
using namespace std;

string matrix[MAX];
int N, M;
// 상 하 좌 우
//int dr[] = {-1, 1, 0, 0};
//int dc[] = {0, 0, -1, 1};

char flag = 'A';

int solve(int i, int j){
    int cnt = 0;
    
    for(int r=i; r<i+8; r++){
        for(int c=j; c<j+8; c++){
            if(flag == 'W' && (r-i)%2 == 0){
                if((c-j)%2 == 0 && matrix[r][c] == 'B') cnt++;
                else if((c-j)%2 == 1 && matrix[r][c] == 'W') cnt++;
            }
            else if(flag == 'W' && (r-i)%2 == 1){
                if((c-j)%2 == 0 && matrix[r][c] == 'W') cnt++;
                else if((c-j)%2 == 1 && matrix[r][c] == 'B') cnt++;
            }
            else if(flag == 'B' && (r-i)%2 == 0){
                if((c-j)%2 == 0 && matrix[r][c] == 'W') cnt++;
                else if((c-j)%2 == 1 && matrix[r][c] == 'B') cnt++;
            }
            else if(flag == 'B' && (r-i)%2 == 1){
                if((c-j)%2 == 0 && matrix[r][c] == 'B') cnt++;
                else if((c-j)%2 == 1 && matrix[r][c] == 'W') cnt++;
            }
        }
    }
    return cnt;
}



int main(void){
    cin >> N >> M;
    int result = 100;
    
    for(int i=0; i<N; i++){
        cin >> matrix[i];
    }
    // 8x8 떼어내기
    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){ // 인덱스주의
            flag = 'B';
            result = min(result, solve(i,j));
            flag = 'W';
            result = min(result, solve(i,j));
        }
    }
    cout << result;
}
