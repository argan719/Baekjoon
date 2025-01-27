#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    int n;
    for(int i=0;i<9;i++){
        cin >> n;
        v.push_back(n);
    }
    cout << *max_element(v.begin(), v.end()) << endl;
    cout << max_element(v.begin(), v.end()) - v.begin() + 1;
}
