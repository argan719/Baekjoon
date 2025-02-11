#include<bits/stdc++.h>
using namespace std;
bool compare(int a, int b){
    return a > b;
}

int main(void){
    int N;
    cin >> N;
    string s;
    s = to_string(N);
    vector<char> result;
    
    for(int i=0;i<s.length();i++){
        result.push_back(s[i]);
    }
    sort(result.begin(), result.end(), compare);
    
    for(int i=0;i<result.size();i++){
        cout << result[i];
    }
    
}