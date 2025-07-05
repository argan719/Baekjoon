#include<iostream>
#define MAX 110
using namespace std;

int N;
int arr[MAX];
int result[MAX];


int main(void){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    int pos;
    result[1] = 1;  // 1이 첫번째
    for(int i=2; i<=N; i++){
        pos = i;
        pos -= arr[i];
        
        if(result[pos]!=0) {
            for(int k=i; pos<k; k--){
                result[k] = result[k-1];
            }
        }
        result[pos] = i;
    }
    
    for(int i=1; i<=N; i++){
        cout << result[i] << " ";
    }
    
}