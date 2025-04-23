#include <iostream>

using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;

    // Please write your code here.
    if(a <= 11){
        if(b < 11 || ( b == 11 && c < 11)) {
            cout << -1;
            exit(0);
        }
    }

    int init = 11*24*60 + 11*60 + 11;
    int end = a*24*60 + b*60 + c;

    cout << end - init;

    return 0;
}