#include <iostream>
#define MAX 101
using namespace std;

int arr[MAX];

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    float sum = 0;
    float avg = 0;
    int cnt = 0;

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    for(int i=0;i<N;i++){
        for(int j=i; j<N;j++){
            sum = 0;
            avg = 0;
            for(int k=i; k<=j; k++){
                sum += arr[k];
            }
            avg = sum/(j-i+1);
            for(int k=i; k<=j; k++){
                if(arr[k] == avg) {
                    cnt++; break;
                }
            }
        }
    }

    cout << cnt;


    return 0;
}