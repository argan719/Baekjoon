#include<iostream>
#include<cstring>
using namespace std;

int main(void){
    string input;
    int T;
    cin >> T;
    
    for(int t=0; t<T; t++){
        cin >> input;
        cout << input[0] << input[input.size()-1] << endl;
    }
}