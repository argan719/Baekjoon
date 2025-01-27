#include<iostream>
#include<string>
using namespace std;

int main(){
    int N;
    string n;
    int sum = 0;
    
    cin >> N;
    cin >> n;
    
    for(int i=0;i<N;i++){
        sum += n[i] - '0';
    }
    cout << sum;
}