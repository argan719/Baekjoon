#include<iostream>
using namespace std;

int N;
int main(void){
    cin >> N;
    
    // 245 => 245 + 2 + 4 + 5 = 256
    // 256의 생성자 245
    
    // N , N의 가장 작은 생성자.
    // m
    // m +
    // 무조건 N보다 작은 값.
    // m - N <0
    // 1000000 -> 999999 9*6=54
    
    int start = N - 100;
    int end = N;
    int sum = 0;
    int result = 0;
    int nn;
    
    
    for(int n=start; n < N; n++){
        sum = n;
        nn = n;
        while(nn!=0){
            sum += nn%10;
            nn = nn/10;
        }
        if(sum == N) {
            result = n;
            break;
        }
    }
    cout << result;
}
