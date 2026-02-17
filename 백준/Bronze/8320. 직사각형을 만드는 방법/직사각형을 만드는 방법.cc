#include<iostream>
using namespace std;

int N;
int main(){
    cin >> N;
    int cnt = 0;
    int sum = 0;
    // 10^8
    for(int i=1; i<=N; i++){
        cnt = 0;
        for(int j=1; j<=i; j++){
            if(i % j == 0) cnt++;
        }
        sum += cnt/2;
        if(cnt % 2 != 0) sum++;
    }
    cout << sum;
}