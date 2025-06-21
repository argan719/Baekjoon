#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void){
    int N;
    cin >> N;
    int n;
    vector<int> vec;
    for(int i=0; i<N;i++){
        cin >> n;
        vec.push_back(n);
    }
    sort(vec.begin(), vec.end());
    for(int i=0;i<N;i++){
        cout << vec[i] << endl;
    }
}