#include<iostream>
#include<cmath>
using namespace std;

int arr[10];
int sum;

void input(){
    for(int i=0; i<10; i++){
        cin >> arr[i];
    }
}

void solve(){
    for(int i=0; i<10; i++){
        sum += arr[i];
        if(i == 9) break;
        if(abs(sum - 100) < abs(sum + arr[i+1] - 100)) break;
    }
    cout << sum;
}

int main(){
    input();
    solve();
}