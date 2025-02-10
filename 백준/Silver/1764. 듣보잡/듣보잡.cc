#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    
    set<string> cant_hear;
    set<string> cant_see;
    set<string> total;
    vector<string> result;
    
    
    string name;
    for(int i=0;i<N;i++){
        cin >> name;
        cant_hear.insert(name);
        total.insert(name);
    }
    for(int i=0;i<M;i++){
        cin >> name;
        cant_see.insert(name);
        total.insert(name);
    }
    
    auto iter = total.begin();
    for(;iter!=total.end();iter++){
        name = *iter;
        if(cant_hear.find(name) != cant_hear.end() && cant_see.find(name) != cant_see.end()){
            result.push_back(name);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }
}