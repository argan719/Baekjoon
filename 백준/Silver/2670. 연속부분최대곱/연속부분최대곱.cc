#include<iostream>
#include<iomanip>
#define MAX 10001
using namespace std;

double arr[MAX];
int main(void){
    int N;
    cin >> N;
    double max = 0.0;
    double mul = 1.0;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i<N; i++){ // <= < ?
        if(mul <= 1.0) mul = arr[i]; // 내 값 vs 내 값*(0.9 ..)
        else mul *= arr[i];
        if(max < mul) max = mul;
    }
    cout << fixed << setprecision(3) << max;
    
}