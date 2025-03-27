#include<stdio.h>
#define MAX 101
int matrix[MAX][MAX];
int N;

void input();

int main(void){
    int cnt = 0;
    input();
    
    for(int i=0;i<100; i++){
        for(int k=0;k<100; k++){
            if(!matrix[i][k]) continue;
                        
            if(i == 0 || !matrix[i-1][k]) cnt++;
            if(i == 99 || !matrix[i+1][k]) cnt++;
            if(k == 0 || !matrix[i][k-1]) cnt++;
            if(k == 99 || !matrix[i][k+1]) cnt++;
        }
    }
    printf("%d", cnt);
}

void input(){
    int x,y;
    scanf("%d", &N);
    
    for(int i=0;i<N;i++){
        scanf("%d %d", &x, &y);
        
        for(int i=x; i<x+10; i++){
            for(int k=y; k<y+10; k++)
                matrix[i][k] = 1;
        }
    }
}