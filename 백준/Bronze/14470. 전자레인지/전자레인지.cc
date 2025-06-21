#include <iostream>
#include <cstdlib>
using namespace std;

int main(void){
    int A, B, C, D, E;
    
    cin >> A;
    cin >> B; 
    cin >> C; 
    cin >> D; 
    cin >> E;
    
    int cnt = 0;
    
    // 얼어있을 경우
    if(A < 0){
        cnt += D;
        cnt += abs(A) * C;
        cnt += B * E;
    } // 얼어 있지 않을 경우
    else if(A > 0) {
        cnt = (B - A) * E;
    }
    
    cout << cnt;
    
    
    
    
}