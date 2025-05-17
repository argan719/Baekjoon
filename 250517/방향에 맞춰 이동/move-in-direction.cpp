#include <iostream>
using namespace std;

int dx[] = {-1, 1, 0, 0};  // W, E, N, S
int dy[] = {0, 0, 1, -1};
int main() {
    // Please write your code here.
    int N;
    cin >> N;

    int distance;
    char direction;
    int x = 0;
    int y=0;
    for(int i=0;i<N;i++){
        cin >> direction >> distance;
        if(direction == 'W'){
            x += dx[0] * distance;
        }
        else if(direction == 'E'){
            x += dx[1] * distance;
        }
        else if(direction == 'N'){
            y += dy[2] * distance;
        }
        else{
            y += dy[3] * distance;
        }

    }

    cout << x << " " << y;
    return 0;
}