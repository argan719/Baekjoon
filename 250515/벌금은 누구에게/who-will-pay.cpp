#include <iostream>
#define MAX 101
using namespace std;

int arr[MAX];

int main() {
    // Please write your code here.
    int N, M, K;
    cin >> N >> M >> K;

    int num;
    int i;

    for(i=0;i<M;i++){
        cin >> num;
        arr[num]++;
        if(arr[num] >= K) {
            cout << num;
            break;
        } 
    }
    if(i >= M) cout << -1;


    return 0;
}