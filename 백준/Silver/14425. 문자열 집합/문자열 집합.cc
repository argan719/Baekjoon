#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    
    string n;
    int cnt = 0;
    set<string> group;
    vector<string> test;
    for(int i=0;i<N;i++){
        cin >> n;
        group.insert(n);
    }
    
    for(int i=0;i<M;i++){
        cin >> n;
        test.push_back(n);
    }
    set<string>::iterator it;
    for(int i=0;i<M;i++){
        it = group.find(test[i]);
        if(it != group.end()) cnt++;
    }
    cout << cnt;
}