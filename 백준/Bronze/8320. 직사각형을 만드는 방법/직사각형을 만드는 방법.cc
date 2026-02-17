#include<iostream>
using namespace std;

int N;
int main(){
    cin >> N;
    int cnt = 0;
    for(int i=1; i<=N; i++){
        for(int j=i; j<=N; j++){
            if(i * j <= N) cnt++;
        }
    }
    cout << cnt;
}