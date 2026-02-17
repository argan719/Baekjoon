#include<iostream>
using namespace std;

int A,B,C,D,E;

void input(){
    cin >> A >> B >> C >> D >> E;
}

void solve(){
    int result = 0;
    
    if(A < 0){
        A = A * -1;
        result += A * C;
        result += D;
        result += B * E;
    }
    else{
        result = (B - A) * E;
    }
    cout << result;
}

int main(){
    input();
    solve();
}