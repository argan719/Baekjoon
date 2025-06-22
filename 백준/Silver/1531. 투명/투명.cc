#include<iostream>
#define MAX 101
using namespace std;

int matrix[MAX][MAX];
int arr[50][4]; // left x, y, right x, y

int main(void){
    int N, M;
    int cnt = 0;
    
    cin >> N >> M;
    for(int i=0; i<N;i++){
        // r c x y
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
        
        for(int r=arr[i][0]; r<=arr[i][2]; r++){
            for(int c = arr[i][1]; c<=arr[i][3]; c++){
                matrix[r][c]++;
            }
        }
    }
    
    for(int i=1; i<=100;i++){
        for(int j=1; j<=100; j++){
            if(matrix[i][j] > M) cnt++;
        }
    }
    cout << cnt;
    
   
}