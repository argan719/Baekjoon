#include<iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    
    int cnt = 0;
    cnt += n;
    
    for(int i=2; i<n; i++){
        for(int j=i; j<n; j++){
            if(i*j > n) break;
            cnt++;
        }
    }
    cout << cnt;
    
    
}