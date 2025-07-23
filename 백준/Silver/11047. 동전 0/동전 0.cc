#include<iostream>
#define MAX 11
using namespace std;

int N, K;
int arr[MAX];
int main(void){
    cin >> N >> K;
    int cnt = 0;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    // 금액 큰거부터 하는게 좋으므로
    // 오름차순으로 주어졌음 -> 뒤에서부터 탐색하면 된다
    for(int i=N-1; i>=0; i--){
        if(arr[i] > K) continue;
        while(arr[i] <= K){
            K = K - arr[i];
            cnt++;
        }
    }
    cout << cnt;
}