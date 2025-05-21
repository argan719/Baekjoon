#include <iostream>
#define MAX 1001
#define MAX_INPUT 101
using namespace std;

int matrix[MAX][MAX];

char direction[MAX_INPUT];
int dist[MAX_INPUT];

int dr[] = {0, 1, -1, 0};  // 서 남 북 동
int dc[] = {-1, 0, 0, 1};

int main() {
    // Please write your code here.
    int N;
    cin >> N;


    int cnt = 0;
    int dir_idx = 0;
    int r = 0;
    int c = 0;
    int i;
    
    for(i=0;i<N;i++){
        cin >> direction[i] >> dist[i];
    }

    for(i=0; i<N;i++){
        if(direction[i] == 'W'){
           dir_idx = 0;
        }
        else if(direction[i]== 'S'){
            dir_idx = 1;
        }
        else if(direction[i] == 'N'){
            dir_idx = 2;
        }else{
            dir_idx = 3;
        }

        for(int k=0;k<dist[i]; k++){

            r += dr[dir_idx];
            c += dc[dir_idx];
            cnt++;
           // if(r < 0 || c < 0 ) break;
            if(r == 0 && c == 0) {cout << cnt; exit(0);}
        }
    }
    if(i == N) cout << -1;

    return 0;
}