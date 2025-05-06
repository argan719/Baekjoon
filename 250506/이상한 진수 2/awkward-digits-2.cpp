#include <iostream>
#include<climits>
#include <cmath>
using namespace std;

int arr[11];

int main() {
    // Please write your code here.
    string num;
    cin >> num;

    int max = INT_MIN;
    for(int i=0;i<num.length(); i++){
        arr[i] = num[i] - '0';
    }


    int i;
    for(i=1;i<num.length(); i++){
        if(arr[i] == 0) {
            arr[i] = 1;
            break;
        }
    }
    if(i == num.length()){
        arr[i-1] = 0;
    }

    int sum = 0;
    int cnt = 0;
    for(int i=num.length()-1;i>=0; i--){
        sum += arr[i] * ((int)pow (2, cnt));
        cnt++;
    }
    cout << sum;


    return 0;
}