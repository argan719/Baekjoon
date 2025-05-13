#include <iostream>
#define MAX 1001
using namespace std;

int arr[MAX];

int main() {
    // Please write your code here.
    int N;
    int T;

    cin >> N >> T;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    int max = 0; 
    int cnt = 0;
    for(int i=0;i<N;i++){
        if(arr[i] > T) {
            cnt++;
            if(max < cnt) max = cnt;
        }
        else cnt = 0;
    }

    cout << max;
    return 0;
}