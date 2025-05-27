#include <iostream>
#include<algorithm>
#define MAX 101
using namespace std;

int arr[MAX];

int main() {
    // Please write your code here.
    int N, K;
    cin >> N >> K;

    int sum = 0;
    int max = -1;

    for(int i=0; i<N;i++){
        cin >> arr[i];
    }

    for(int i=0;i<= N-2; i++){
        sum = 0;
        for(int k=i; k< i+K; k++){
            sum += arr[k];
        }
        if(max < sum) max = sum;
    }

    cout << max;

    return 0;
}