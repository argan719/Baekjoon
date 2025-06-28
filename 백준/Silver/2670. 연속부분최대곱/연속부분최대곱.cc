#include<iostream>
#include <cmath>
#define MAX 10001
using namespace std;

double arr[MAX];

int main(void){
    int N;
    cin >> N;
    double sum;
    double max = 0.0;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i<N; i++){
        sum = 1.0;
        for(int j=i; j<N; j++){
            sum = sum * arr[j];
            if(sum > max) max = sum;
        }
    }
    
    cout << fixed;
    cout.precision(3);

    cout << max;
    
}
