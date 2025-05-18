#include <iostream>
#include <cstring>
#define MAX 100001
using namespace std;

// char order[MAX];
string order;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};  // 북 오 남 왼

int main() {
    // Please write your code here.
    cin >> order;

    int dir_idx = 0;
    int x = 0;
    int y = 0;

    for(int i=0;i<order.length(); i++){
        if(order[i] == 'L'){
            dir_idx = (dir_idx - 1 + 4) % 4;
        }
        else if(order[i] == 'R'){
            dir_idx = (dir_idx + 1) % 4;
        }
        else {
            x += dx[dir_idx]; 
            y += dy[dir_idx];
        }
    }

    cout << x << " " << y;

    return 0;
}