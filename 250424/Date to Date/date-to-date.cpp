#include <iostream>

using namespace std;

int m1, d1, m2, d2;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    // Please write your code here.
    int arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum1 = 0;
    int sum2 = 0;

    for(int i=1; i< m2; i++){
        sum2 += arr[i];
    }
    sum2 += d2;

    for(int i=1; i< m1; i++){
        sum1 += arr[i];
    }
    sum1 += d1;

    cout << sum2 - sum1;

    return 0;
}