#include<iostream>
#define MAX 100
using namespace std;

int matrix[MAX][MAX];

int main(void){
    int c;
    int x,y;
    cin >> c;
    
    int cnt = 0;
    for(int i=0;i<c;i++){
        cin >> x >> y;
        
        for(int i=x; i<x+10; i++){
            for(int k=y; k<y+10; k++){
                if((0<=i && i<= 99) && (0<=k && k<=99) && matrix[i][k] == 0) {
                    matrix[i][k] = 1;
                    cnt++;
                }
            }
        }
    }
    
    cout << cnt;
}