#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;

int main(void){
    int A,B,C;
    cin >> A;
    cin >> B;
    cin >> C;
    
    //a = int(A);  b = int(B);  c = int(C);
    cout << A + B - C << endl;
    
    string a, b, c;
    a = to_string(A);
    b = to_string(B);
    c = a + b;
    
    cout << stoi(c) - C;
    
}