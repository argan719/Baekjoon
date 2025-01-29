#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int sum = 1;
    
    if(s.length() == 1 && s[0] == ' ') cout << 0;
    else{
        for(int i=1;i<s.length()-1;i++){
            if(s[i] == ' ') sum++;
        }
        cout << sum;
    }
    
}