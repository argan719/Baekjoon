#include <iostream>
#include <climits>
#define MAX 2001
using namespace std;

int x1[3];
int x2[3];
int y1[3];
int y2[3];

int matrix[MAX][MAX];

int main() {
    // Please write your code here.
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];
    cin >> x1[2] >> y1[2] >> x2[2] >> y2[2];
    x1[1] += 1000;
    y1[1] += 1000;
    x2[1] += 1000;
    y2[1] += 1000;
    x1[2] += 1000;
    y1[2] += 1000;
    x2[2] += 1000;
    y2[2] += 1000;

    for(int i=1; i<3; i++){
        for(int x = x1[i]; x<x2[i]; x++){
            for(int y=y1[i]; y<y2[i]; y++){
                matrix[x][y] = i;  
            }
        }
    }


    int min_x = INT_MAX;
    int min_y = INT_MAX;
    int max_x = INT_MIN;
    int max_y = INT_MIN;

    int flag = 0;
    for(int i=0; i<MAX ; i++){
        for(int k=0; k<MAX; k++){
            if(matrix[i][k] == 1) {
                if(min_x > i) min_x = i;
                if(min_y > k) min_y = k;
                if(max_x < i) max_x = i;
                if(max_y < k) max_y = k;
                flag = 1;
            }
        }
    }

    if(!flag) cout << 0;
    else cout << (max_x - min_x + 1) * (max_y - min_y + 1);

    return 0;
}