#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int N;
    int val;
    vector<int> n;
    
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> val;
        n.push_back(val);
    }
    cout << *min_element(n.begin(), n.end()) << " " << *max_element(n.begin(), n.end());
}
