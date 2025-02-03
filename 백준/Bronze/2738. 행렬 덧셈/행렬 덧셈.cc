#include<iostream>
#define MAX 101
using namespace std;

int arr_A[MAX][MAX];
int arr_B[MAX][MAX];

int main(void){
    int N, M;
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int k=0;k<M;k++){
            cin >> arr_A[i][k];
        }
    }
    for(int i=0;i<N;i++){
        for(int k=0;k<M;k++){
            cin >> arr_B[i][k];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int k=0;k<M;k++){
            cout << arr_A[i][k] + arr_B[i][k] << " ";
        }
        cout << endl;
    }
}