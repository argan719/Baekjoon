#include <iostream>
#include <climits>
#define MAX 101
using namespace std;

int arr[MAX];

int main() {
    // Please write your code here.
    int N, H, T;
    cin >> N >> H >> T;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    int min = INT_MAX;
    int cost = 0;
    for(int start = 1; start <= N-T+1; start++){
        cost = 0;
        for(int j=start; j< start+T; j++) {
            if(arr[j] != H){
                if(arr[j] > H) cost += arr[j] - H;
                if(arr[j] < H) cost += H -arr[j];
            }
        }
        if(min > cost) min = cost;
    }
    
    cout << min;

    return 0;
}