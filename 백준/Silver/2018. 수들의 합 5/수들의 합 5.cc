#include<iostream>
using namespace std;

int N;
int main(){
    cin >> N;
    int cnt = 0;
    int sum = 1, s = 1, e = 1;
    
    while(e <= N){
        if(sum == N) {cnt++; sum += ++e;}
        if(sum < N) sum += ++e;
        if(sum > N) sum -= s++;
    }
    cout << cnt;
}