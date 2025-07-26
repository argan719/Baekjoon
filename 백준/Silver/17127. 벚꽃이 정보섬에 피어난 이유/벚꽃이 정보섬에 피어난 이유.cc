#include<iostream>
#define MAX 11
using namespace std;

int N;
int arr[MAX];
// 완탐
int mul(int s, int e){
    int ans = 1;
    for(int i=s; i<=e; i++){
        ans *= arr[i];
    }
    return ans;
}
int main(void){
    int max = 0;
    int sum;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i<N-3; i++){ // 인덱스 신경쓰기
        for(int j=i+1; j<N-2; j++){
            for(int k=j+1; k<N-1; k++){
                sum = mul(0, i) + mul(i+1, j) + mul(j+1, k) + mul(k+1, N-1);
                if(max < sum) max = sum;
            }
        }
    }
    cout << max;
}