#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    int sum = 0;
    vector<int> arr;
    for(int i=0;i<5;i++){
        cin >> n;
        sum += n;
        arr.push_back(n);
    }
    sort(arr.begin(), arr.end());
    cout << sum/5 << "\n";
    cout << arr[2] << "\n";
    
}