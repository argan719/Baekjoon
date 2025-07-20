#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(void){
    string str;
    cin >> str;
    string rstr = str;
    reverse(rstr.begin(), rstr.end());
    if(str == rstr) cout << 1;
    else cout << 0;
}