#include<iostream>
#include<algorithm>
#define MAX 10001
using namespace std;

int N;
int matrix[301] = {0,};
                   
int main(void){
    cin >> N;
    int stair[N+1];
    
    stair[0] =0;
    
    for(int i=1;i<=N;i++){
        cin >> stair[i];
    }
    
    matrix[0] = stair[0];
    matrix[1] = stair[1];
    matrix[2] = stair[2] + stair[1];
    
    for(int i=3; i<=N; i++){
        matrix[i] = max(matrix[i-2], matrix[i-3] + stair[i-1]) + stair[i];
    }
    
    cout << matrix[N];
}