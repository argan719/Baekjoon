#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[5];

int compare(int a, int b){
    if(a > b) return a;
    else return b;
}

int compare_min(int a, int b){
    if(a > b) return b;
    else return a;
}

int main() {
    // Please write your code here.
    int sum = 0;
    for(int i=0; i<5; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    //sort(arr, arr+5);
    // 2명, 1명 -> 총 3명

    int sum_a; 
    int sum_b; 
    int sum_c; // 1명

    int min = INT_MAX;

    int max_val = 0;
    int min_val = 0;

    for(int i=0; i<5; i++){
        sum_c = arr[i];
        for(int j=0; j<5; j++){
            if(i == j) continue;
            for(int k=0; k<5; k++){
                if(i == k || j == k) continue;
                sum_a = arr[j] + arr[k];
                if(sum_a == sum_c) continue;
                sum_b = sum - sum_a - sum_c;
                if(sum_a == sum_b) continue;
                if(sum_b == sum_c) continue;

                max_val = compare(sum_c, compare(sum_a, sum_b));
                min_val = compare_min(sum_c, compare_min(sum_a, sum_b));
                if(min > max_val - min_val) min = max_val - min_val;
            }
        }
    }

    if(min == INT_MAX) cout << -1;
    else cout << min;



    return 0;
}