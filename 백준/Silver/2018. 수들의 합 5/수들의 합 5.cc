// "연속된"자연수의 합
// 덧셈만 가능.
#include<iostream>
#define endl "\n"
using namespace std;

int N;
int main(void){
    cin >> N;
    int sum = 1; // N 하나
  
    int add = 0;
    // 더하다가 N를 넘어가면 stop.
    for(int i=1; i<N; i++){
        add = i;
        for(int j=i+1; j<N; j++){
            add += j;
            if(add == N) { sum++; break;}
            if(add > N) break;
        }
    }
    cout << sum;
}