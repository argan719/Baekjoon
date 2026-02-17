#include<iostream>
using namespace std;
int TC;
int arr[21]; // 1~ 20번 학생
int num;

void solve(){
    int tmp;
    int cnt = 0;
    for(int i=2; i<=20; i++){
        for(int j=1; j<=i-1; j++){
            if(arr[j] <= arr[i]) continue;
            
            tmp = arr[i];
            for(int k=i-1; k >= j; k--){
                arr[k+1] = arr[k];
                cnt++;
            }
            arr[j] = tmp;
        }
    }
    cout << num << " " << cnt << endl;
}

void input(){
    cin >> TC;
    for(int t=1; t<=TC; t++){
        cin >> num;
        for(int i=1; i<=20; i++) cin >> arr[i];
        solve();
    }
}
int main(){
    input();
}