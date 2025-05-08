#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // Please write your code here.
    string A;
    cin >> A;
    int cnt = 0;

    for(int i=0;i<A.length(); i++){
        if(A[i] == '(' && A[i+1] == '(') {
            for(int k= i+2; k<A.length(); k++){
                if(A[k] == ')' && A[k+1] == ')') {
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
    return 0;
}