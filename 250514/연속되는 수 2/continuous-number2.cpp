#include <iostream>
#define MAX 1001
using namespace std;

int arr[MAX];

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    int cnt = 0;
    int max = 1;
    cnt++;
    for(int i=1; i<N;i++){
        if(arr[i-1] == arr[i]) {
            cnt++;
            if(max < cnt) max = cnt;
        }
        else cnt = 1;
    }

    cout << max;


    return 0;
}