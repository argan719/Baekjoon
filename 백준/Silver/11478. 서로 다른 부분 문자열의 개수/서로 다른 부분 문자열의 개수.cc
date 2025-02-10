#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    set<string> result;
    int limit = s.length();
    string r;
    for(int i=1; i<=limit; i++){
        for(int k=0; i+k<=limit; k++){
            r = s.substr(k, i);
            result.insert(r);
        }
    }

    cout << result.size();
}