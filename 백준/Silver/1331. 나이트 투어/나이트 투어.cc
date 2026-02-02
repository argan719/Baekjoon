#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<array>
using namespace std;

int v[7][7]; // 1 - 6
array<string, 36> arr;  // 0 ~ 35
string ans;

void input(){
    for(int i=0; i<36; i++){
        cin >> arr[i];
        
        int a = (int)arr[i][0] - 64;
        
        if(v[a][arr[i][1] - '0']) ans = "Invalid";
        v[a][arr[i][1] - '0'] = 1;
        
    }
}

string solve(){
    if(ans == "Invalid") return ans;
    
    int n;
    for(int i=1; i<36; i++){
        n = abs(((int)arr[i-1][0] - 64) - ((int)arr[i][0] - 64)) + abs((arr[i-1][1] - '0') - (arr[i][1] - '0'));
        if(n != 3 || arr[i-1][0] == arr[i][0] || arr[i-1][1] == arr[i][1] ) return "Invalid";
    }
    
    if(abs(((int)arr[0][0] - 64) - ((int)arr[35][0] - 64)) + abs((arr[0][1] - '0') - (arr[35][1] - '0')) != 3) return "Invalid";
    if(arr[0][0] == arr[35][0] || arr[0][1] == arr[35][1] ) return "Invalid";

    return "Valid";
}


int main(){
    input();
    
    cout << solve();
}