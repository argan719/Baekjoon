#include<iostream>
using namespace std;
int TC;
int arr[21]; // 1~ 20번 학생

void solve(){
    int tmp;
    int cnt = 0;
    for(int i=2; i<=20; i++){
        for(int j=1; j<=i-1; j++){
            if(arr[j] <= arr[i]) continue;
            cnt++;  // 나보다 큰 학생 수만 카운트하면 끝.
        }
    }
    cout << arr[0] << " " << cnt << endl;
}

void input(){
    cin >> TC;
    for(int t=1; t<=TC; t++){
        for(int i=0; i<=20; i++) cin >> arr[i];
        solve();
    }
}
int main(){
    input();
}
