// 주어진 위치에 "차례로" 놓일 경우
// "입력순서로 출력" <- 입력순서로 격자에 1,2,3 마킹
#include<iostream>
#define MAX 1010
#define endl "\n"
using namespace std;

// (1,4)
// r,c
// 너비 = r, 높이 = c

int N;
typedef struct rectangle{
    int rn;
    int cn;
    int r_range;
    int c_range;
}Rec;

Rec rec[101];
//int rn, cn, r_range, c_range;
int matrix[MAX][MAX];
int main(void){
    cin >> N;
    int cnt;
    
    for(int i=0; i<N; i++){
        cin >> rec[i].rn >> rec[i].cn >> rec[i].r_range >> rec[i].c_range;
        
        for(int r=rec[i].rn; r<rec[i].rn+rec[i].r_range; r++){
            for(int c=rec[i].cn; c<rec[i].cn+rec[i].c_range; c++){
                matrix[r][c] = i+1;
            }
        }
    }
    
    /*
    int cnt = 0;
    for(int val=1; val<=N; val++){
        //O(n^2) * N(100)
        for(int i=0; i<=1000; i++){
            for(int j=0; j<=1000; j++){
                if(matrix[i][j] == val) cnt++;
            }
        }
    }*/
    
    
    for(int i=0; i<N; i++){
        cnt = 0;
        for(int r=rec[i].rn; r<rec[i].rn+rec[i].r_range; r++){
            for(int c=rec[i].cn; c<rec[i].cn+rec[i].c_range; c++){
                if(matrix[r][c] == i+1) cnt++;
            }
        }
        cout << cnt << endl;
    }
    
}