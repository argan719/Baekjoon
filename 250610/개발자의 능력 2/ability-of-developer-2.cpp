#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[6];

int main() {
    // Please write your code here.
    int sum = 0;
    for(int i=0; i<6; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    int a, b, c;
    int sum_a = 0;
    int sum_b = 0;
    int sum_c = 0;

    sort(arr, arr+6);
    int max_left = INT_MIN;
    int min_left = INT_MAX;

    int max_right = INT_MIN;
    int min_right = INT_MAX;

    for(int i=0; i<3; i++){
        if(max_left < arr[i]) max_left = arr[i];
        if(min_left > arr[i]) min_left = arr[i];
    }
    for(int i=3; i<6; i++){
        if(max_right < arr[i]) max_right = arr[i];
        if(min_right > arr[i]) min_right = arr[i];
    }

    sum_a = min_left + max_right;
    sum_b = max_left + min_right;
    sum_c = sum - sum_a - sum_b;

    int min_val = min(sum_a, sum_b);
    min_val = min(min_val, sum_c);

    int max_val = max(sum_a, sum_b);
    max_val = max(max_val, sum_c);
    
    
    cout << abs(max_val - min_val);

    return 0;
}