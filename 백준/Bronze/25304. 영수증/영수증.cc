#include<iostream>
using namespace std;

int X, N;
int main(void){
    cin >> X >> N;
    int a,b;
    long long sum = 0;
    
    for(int i=0; i<N; i++){
        cin >> a >> b;
        sum += a * b;
    }
    if(sum == X) cout << "Yes";
    else cout << "No";
}