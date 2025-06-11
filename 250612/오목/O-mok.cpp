#include <iostream>
using namespace std;

int matrix[20][20];

typedef struct rr{
    int x;
    int y;
}result;


int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int cnt = 1;

result search(int i, int j){
    int r,c;
    int cnt = 1;
    result ans;
    ans.x = 0;
    ans.y = 0;

    for(int k=0; k<8; k++){
        r = i + dr[k];
        c = j + dc[k];

        if(r < 1 || c < 1 || r > 19 || c > 19) continue;
        if(matrix[r][c] == 0) continue;

        while(matrix[i][j] == matrix[r][c]){
            cnt++;
            i = r;
            j = c;
            r = i + dr[k];
            c = j + dc[k];
            if(cnt == 3) { ans.x = i;  ans.y = j;}
            if(cnt >=5) return ans;
        }
        cnt = 1;
    }

    ans.x = 0;
    ans.y = 0;
    return ans;
}


int main() {
    result ans;

    for(int i=1; i<=19; i++){
        for(int j=1; j<=19; j++){
            cin >> matrix[i][j];
        }
    }


    int dr, dc;
    int flag=0;
    int cnt = 0;

    for(int i=1; i<=19; i++){
        for(int j=1; j<=19; j++){
            if(matrix[i][j] == 0) continue;
            ans = search(i, j);
            //cout << ans.x << " " << ans.y << endl;

            if(ans.x == 0 && ans.y == 0) continue;
            else{
                flag = 1;
                break;
            }

        }
        if(flag) break;
    }

    if(flag) {
        cout << matrix[ans.x][ans.y] << endl;
        cout << ans.x << " " << ans.y;
    }
    else cout << 0;


    return 0;
}