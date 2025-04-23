#include <iostream>
#include <cstring>

using namespace std;

int m1, d1, m2, d2;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;
    int sum1 = 0; 
    int sum2 = 0;

    // Please write your code here.
    int date[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    for(int i=1; i<m1; i++){
        sum1 += date[i];
    }
    sum1 += d1;

    for(int i=1; i<m2; i++){
        sum2 += date[i];
    }
    sum2 += d2;

    if(sum2 >= sum1) cout << day[(sum2 - sum1)%7];
    else cout << day[(7 + (sum2 - sum1)%7)%7];

    return 0;
}