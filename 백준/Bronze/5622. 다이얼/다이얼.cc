#include<iostream>
#include<cstring>
#include<map>
using namespace std;

int main(void){
    string input;
    cin >> input;
    map<char, int> m;
    int cnt = 2;
    
    int start = 65;
    for(int i=65; i<=82; i++){
        if(i-start == 3) {
            cnt++;
            start = i;
        }
        m.insert({i, cnt});

    }
    m.insert({83, 7});
    m.insert({84, 8});
    m.insert({85, 8});
    m.insert({86, 8});
    m.insert({87, 9});
    m.insert({88, 9});
    m.insert({89, 9});
    m.insert({90, 9});

    
    
    int sum = 0;
    
    for(int i=0; i<input.size(); i++){
        sum += m[input[i]] + 1;
    }
    cout << sum;
}