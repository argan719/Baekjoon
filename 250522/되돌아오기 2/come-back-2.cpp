#include <iostream>
#include <cstring>
using namespace std;
// 0 1 2 3
int dr[] = {0, 1, 0, -1};  // 왼 북 오 남
int dc[] = {-1, 0, 1, 0}; 

string order;

int main() {
    // Please write your code here.
    int r = 0;
    int c = 0;
    int dir_idx = 0;
    int cnt = 0;
    
    cin >> order;
    int i;
    for(i=0;i<order.length(); i++){
        if(order[i] == 'L'){
            dir_idx = (dir_idx - 1 + 4) % 4;
        }
        else if(order[i] == 'R'){
            dir_idx = (dir_idx + 1) % 4;
        }
        else {
            r = r + dr[dir_idx];
            c = c + dc[dir_idx];
        }
        cnt++;
        if(r == 0 && c == 0) break;
    }
    if(i >= order.length()) cout << -1;
    else cout << cnt;
    


    return 0;
}