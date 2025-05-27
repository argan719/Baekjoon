#include <iostream>
#include<algorithm>
#include<climits>
#define MAX 10001
using namespace std;

int arr[MAX];
int main() {
    // Please write your code here.
    int N, K;
    cin >> N >> K;

    int pos;
    char val;
    int max_pos = INT_MIN;
    int max = INT_MIN;

    for(int i=0;i<N;i++){
        cin >> pos >> val;
        if(val == 'G') arr[pos] = 1;
        else if(val == 'H') arr[pos] = 2;
        if(pos > max_pos) max_pos = pos;
    }

    int sum = 0;
    for(int i=1;i<=max_pos; i++){
        sum = 0;
        for(int k=i; k<= i+K; k++){
            sum += arr[k];
        }
        if(max < sum) max = sum;
    }

    cout << max;

    return 0;
}