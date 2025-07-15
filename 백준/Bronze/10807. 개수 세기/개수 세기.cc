#include<iostream>
#include<vector>
using namespace std;

vector<int> vec;
int main(void){
    int N, v;
    int cnt = 0;
    int n;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> n;
        vec.push_back(n);
    }
    cin >> v;
    
    for(auto n : vec){
        if(n == v) cnt++;
    }
    cout << cnt;
}