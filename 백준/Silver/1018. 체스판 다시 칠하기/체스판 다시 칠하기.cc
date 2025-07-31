#include<iostream>
#include<algorithm>
#include<cstring>
#define MAX 51
using namespace std;

int N, M;
char matrix[MAX][MAX];

int main(void){
    cin >> N >> M;
    string str;
    int cnt = 0;
    int min_val = 300;
    
    for(int i=0; i<N; i++){
        cin >> str;
        for(int j=0; j<M; j++){
            matrix[i][j] = str[j];
        }
    }
    
    for(int r=0; r<= N-8; r++){
        for(int c=0; c<=M-8; c++){
            cnt = 0;
            for(int i=r; i<r+8; i++){
                for(int j=c; j<c+8; j++){
                    if((i+j)%2 == 0 && matrix[i][j] != 'W') cnt++;
                    else if((i+j)%2 == 1 && matrix[i][j] != 'B') cnt++;
                }
            }  // 2가지 경우에 대해서만 고려
            // 맨 왼 앞이 W인 체스판일 때 색칠해야 할 개수가 적은지,
            // 맨 왼 앞이 B인 체스판일 때 색칠해야 할 개수가 적은지 비교
            min_val = min(min_val, min(cnt, 64-cnt));
        }
    }
    cout << min_val;
}
