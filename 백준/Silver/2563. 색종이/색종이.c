// 텔레칩스 임베디드 스쿨
// c언어로 다시 해봄

#include<stdio.h>
#define MAX 100

int matrix[MAX][MAX];

int main(void){
    int n;
    int x,y;
    int cnt = 0;
    
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &x, &y);
        
        for(int i=x; i<x+10; i++){
            for(int j=y; j<y+10; j++){
                if((0 <= i && i <= 99) && (0<=j && j <=99) && !matrix[i][j]){
                    matrix[i][j] = 1;
                    cnt++;
                }
            }
        }
    }
    printf("%d", cnt);
}