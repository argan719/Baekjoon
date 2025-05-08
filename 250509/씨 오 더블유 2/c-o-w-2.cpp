#include <iostream>
#include <cstring>
using namespace std;


int main() {
    // Please write your code here.
    string str;
    int N;
    cin >> N;
    cin >> str;

    int cnt = 0;

    for(int i=0; i<str.length(); i++){
        if(str[i] == 'C'){
            for(int j=i+1; j<str.length(); j++){
                if(str[j] == 'O') {
                    for(int k=j+1; k<str.length(); k++){
                        if(str[k] == 'W') cnt++;
                    }
                }
            }
        }
    }

    cout << cnt;


    return 0;
}