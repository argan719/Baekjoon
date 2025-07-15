#include<iostream>
#define MAX 101
using namespace std;

int N, M;
int arr[MAX];

int main(void){
    int a,b,k;
    
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> a >> b >> k;
        for(int j=a; j<=b; j++){
            arr[j] = k;
        }
    }
    for(int i=1; i<=N; i++){
        cout << arr[i] << " ";
    }
    
}