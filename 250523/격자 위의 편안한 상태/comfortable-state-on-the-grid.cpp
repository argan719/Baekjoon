#include <iostream>
#define MAX 101
#define MAX_M 10001
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int matrix[MAX][MAX];

int r[MAX_M];
int c[MAX_M];

int main() {
    // Please write your code here.
    int N, M;
    cin >> N >> M;

    int dr, dc;
    int cnt = 0;

    for(int i=0;i<M;i++){
        cin >> r[i] >> c[i];
    }

    for(int i=0;i<M;i++){
        matrix[r[i]][c[i]] = 1;

        for(int j=0;j<4; j++){
            dr = r[i] + dx[j];
            dc = c[i] + dy[j];
            if((dr > 0 && dc > 0 && dr <=N && dc <= N) && matrix[dr][dc]) cnt++;
        }
        if(cnt == 3) cout << 1;
        else cout << 0;
        cout << endl;
        cnt = 0;
    }



    return 0;
}