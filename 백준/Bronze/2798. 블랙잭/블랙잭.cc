#include<iostream>
#define MAX 101
using namespace std;

int N, M;
int arr[MAX];
int main(void){
    int sum = 0;
    int max_val = 0; // n은 무조건 1이상.
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    
    for(int i=0; i<=N-3; i++){
        for(int j=i+1; j<=N-2; j++){//인덱스주의
            for(int k=j+1; k<=N-1; k++){
                sum = arr[i] + arr[j] + arr[k];
                if(sum > M) continue;
                if(max_val < sum) max_val = sum;
            }
        }
    }
    cout << max_val;
}