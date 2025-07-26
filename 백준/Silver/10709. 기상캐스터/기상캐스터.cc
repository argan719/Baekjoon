// 단, 처음부터 구역에 구름이 있었던('c') 경우에는 0,
// 몇 분이 지나도 구름이 뜨지 않을 경우 (<- 본인보다 왼쪽이 전부 .인경우) -1 출력

#include<iostream>
#include<cstring>
#define MAX 101
using namespace std;

int matrix[MAX][MAX];
int H, W;
int main(void){
    cin >> H >> W;
    string str;
    
    for(int i=0; i<H; i++){
        cin >> str;
        for(int j=0; j<W; j++){
            if(str[j] == 'c') matrix[i][j] = 0; //구름
            else matrix[i][j] = -1; // 구름X
        }
    }
    
    int move;
    int cnt = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(matrix[i][j] == 0) continue;
            if(matrix[i][j] == -1) {
                move = j;
                cnt = 0;
                while(move > 0) {
                    cnt++;
                    if(matrix[i][--move] == 0) {
                        matrix[i][j] = cnt;
                        break;
                    }
                }
            }
        }
    }
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
}