// 8:18
#include<iostream>
#include<iomanip>
#define MAX 10001
using namespace std;

double arr[MAX];
int main(void){
    int N;
    cin >> N;
    double max = 0;
    double ans = 1;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    for(int j=0; j<N; j++){
        for(int i=j; i<N; i++){
            ans *= arr[i];
            if(max < ans) {
                max = ans;
            }
        }
        ans = 1;
    }
    cout << fixed << setprecision(3) << max;
    
}