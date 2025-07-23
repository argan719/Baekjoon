#include<iostream>
#include<vector>
#define MAX 15
using namespace std;

int T;
int n, k;
vector<int> vec;

int matrix[MAX][MAX]; // r 해당 층, c 해당 호

int main(void){
    cin >> T;
    int sum = 0;
    
    // 14^3
    for(int r=0; r<=14; r++){
        for(int c=1; c<=14; c++){
            if (r == 0) {
                matrix[r][c] = c;
            }
            else {
                for(int j=1; j<=c; j++){
                    matrix[r][c] += matrix[r-1][j];
                }
            }
        }
    }
    
    for(int t=0; t<T; t++){
        cin >> k;
        cin >> n;
        vec.push_back(matrix[k][n]);
    }
    
    for(auto cur : vec){
        cout << cur << endl;
    }
}
