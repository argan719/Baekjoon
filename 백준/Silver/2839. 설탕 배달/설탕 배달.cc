#include<iostream>
using namespace std;

int N;
int ans; int sum;

void solve(){
    sum = N;
    
    if(N == 3) { cout << 1; return; }
    if(N == 4) {cout << -1; return; }
    
    // N >= 5인 경우
    if(N%5 == 0) { cout << N/5; return;}
    
    int mul = sum/5;
    
    while(mul >= 0){
        if((sum - (5 * mul)) % 3 == 0) {
            cout << mul + (sum - (5 * mul))/3; return;
        }
        mul--;
    }
    cout << -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    solve();
}