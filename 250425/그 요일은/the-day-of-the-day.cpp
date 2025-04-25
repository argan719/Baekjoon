#include <iostream>

using namespace std;

int m1, m2, d1, d2;
string A;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> A;

    // Please write your code here.
    string day[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    int date[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum1 = 0;
    int sum2 = 0;

    if(A == "Mon"){
        d1 += 0;
    }
    else if(A == "Tue"){
        d1 += 1;
    }
    else if(A == "Wed"){
        d1 += 2;
    }
    else if(A == "Thu"){
        d1 += 3;
    }
    else if(A == "Fri"){
        d1 += 4;
    }
    else if(A == "Sat"){
        d1 += 5;
    }
    else if(A == "Sun"){
        d1 += 6;
    }


    for(int i=0; i<m1; i++){
        sum1 += date[i];
    }
    sum1 += d1;

    for(int i=0;i<m2; i++){
        sum2 += date[i];
    }
    sum2 += d2;

    cout << (sum2-sum1)/7 + 1;



    return 0;
}