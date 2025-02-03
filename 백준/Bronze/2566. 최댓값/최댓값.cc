#include<iostream>
#define MAX 10
using namespace std;

//int arr[MAX][MAX];

int main(void){
    int max = 0;
    int max_x, max_y;
    int input;
    
    for(int i=1; i<=9; i++){
        for(int k=1;k<=9; k++){
            cin >> input;
            
            if(max <= input){
                max = input;
                max_x = i;  max_y = k;
            }
        }
    }
    
    cout << max << endl;
    cout << max_x << " " << max_y;
    
}