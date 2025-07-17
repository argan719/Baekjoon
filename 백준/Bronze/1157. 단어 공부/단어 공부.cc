#include<iostream>
#include<cstring>
#include<vector>
#define MAX 50
using namespace std;

int arr[MAX];
int main(void){
    string order;
    cin >> order;
    int max_val = 0;
    int cnt = 0;
    char answer;
    
    for(int i=0; i<order.size(); i++){
        // 65 + 26 = 90
        if(order[i] > 90) order[i] -= 32;
        arr[order[i] - 65]++;
        if(max_val < arr[order[i] - 65]) max_val = arr[order[i] - 65];
    }
    
    for(int i=0; i<26; i++){
        if(arr[i] == max_val) {
            cnt++;
            answer = i+65;
        }
    }
    if(cnt >=2 ) cout << "?";
    else cout << answer;
}