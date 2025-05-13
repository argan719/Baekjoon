#include <iostream>
#define MAX 1001
using namespace std;

int arr[MAX];

int main() {
    // Please write your code here
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    int flag = 0;
    int cnt = 1;
    int max = 1;
    flag = (arr[0] > 0) ? 1 : 0;
    for(int i=1;i<N;i++){
        if(arr[i] > 0 && flag) cnt++;
        else if(arr[i] < 0 && !flag) cnt++;
        else {
            cnt = 1;
            flag = (arr[i] > 0) ? 1 : 0;
        }
        if(max < cnt) max = cnt;
    }

    cout << max;

    return 0;
}