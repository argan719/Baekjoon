#include <iostream>
#include <climits>
#define MAX 101
using namespace std;

int arr[MAX][2];

int main() {
    // Please write your code here.
    int N; 
    cin >> N;
    int min = INT_MAX;
    int result;

    for(int i=0; i<N;i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
           result = (arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1]) * (arr[i][1] - arr[j][1]);
           if(min > result) min = result;
        }
    }

    cout << min;


    return 0;
}