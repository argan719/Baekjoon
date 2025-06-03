#include <iostream>
#include <climits>
using namespace std;

int arr[7];

int main() {
    // Please write your code here.
    int sum = 0;
    for(int i=1;i<=6; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    int sum1 = 0;
    int sum2 = 0;
    int min = INT_MAX;
    for(int i=1; i<=4; i++){
        for(int j=i+1; j<=5; j++){
            for(int k=j+1; k<=6; k++){
                sum1 = arr[i] + arr[j] + arr[k];
                sum2 = sum - sum1;
                if(abs(sum1 - sum2) < min) min = abs(sum1 - sum2);
            }
        }
    }

    cout << min;

    return 0;
}