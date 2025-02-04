#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

int main(void){
    vector<string> vec(5);
    string str;
    
    for(int i=0;i<5;i++){
        cin >> str;
        vec[i] = str;
    }
    
    for(int k=0;k<15;k++){
        for(int i=0;i<5;i++){
            if(vec[i].size() > k) cout << vec[i][k];
        }
    }
}