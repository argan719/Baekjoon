#include<iostream>
#include<cstring>
using namespace std;

int main(void){
    string str;
    cin >> str;
    int sum = 0;
    
    sum += 10;
    for(int i=1; i<str.size(); i++){
        if(str[i-1] != str[i]) sum+= 10;
        else sum += 5;
    }
    cout << sum;
}