#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    
    set<int> A;
    set<int> B;
    vector<int> result;
    
    int n;
    for(int i=0;i<N;i++){
        cin >> n;
        A.insert(n);
    }
    for(int i=0;i<M;i++){
        cin >> n;
        B.insert(n);
    }
    
    // A-B
    auto iter = A.begin();
    for(;iter != A.end(); iter++){
        if(B.find(*iter) != B.end()) continue;
        else result.push_back(0);
    }
    iter = B.begin();
    for(;iter !=B.end();iter++){
        if(A.find(*iter) != A.end()) continue;
        else result.push_back(0);
    }
    
    cout << result.size();
}