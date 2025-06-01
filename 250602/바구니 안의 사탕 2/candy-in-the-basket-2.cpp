#include <iostream>
#define MAX 101
using namespace std;

int arr[MAX];

int main() {
    // Please write your code here.
    int N, K;
    cin >> N >> K;

    int sum = 0;
    int max = -1;

    int candy;
    int x;
    for(int i=0; i<N;i++){
        cin >> candy >> x;
        arr[x]+= candy;
        sum += candy;
    }
    if(K >= 50) {
        cout << sum;
        exit(0);
    }

    // int c = 0;
    for(int c = 0; c<=100; c++) {
        sum = 0;
        for(int i=c-K; i<=c+K; i++){
            if(i < 0 || i > 100) continue;
            sum += arr[i];
        }
        if(max < sum) max = sum;
    }

    cout << max;

    return 0;
}