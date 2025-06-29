#include<iostream>
#include<algorithm>
#include<cstring>
#define MAX 51
using namespace std;

int N, M;
//int matrix[MAX][MAX];
string arr[MAX];

int main(void){
    cin >> N >> M;
    int result = 1;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    int max_len = min(N, M);
    //int max_len = max(N, M);
    
    for(int len = max_len; 1 <= len; len--){
        
        for(int r=0; r<=N-len; r++){
            for(int c=0; c<=M-len; c++){
                
                if(arr[r][c] == arr[r+len-1][c] && arr[r+len-1][c] == arr[r][c+len-1] && arr[r][c+len-1] == arr[r+len-1][c+len-1] ){
                    if(result < len) result = len;
                }
            }
        }
        
    }
    
    cout << result * result;
    
}