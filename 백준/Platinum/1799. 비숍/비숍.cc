#include<iostream>
#include<cstring>
#include<vector>
#define MAX 11
using namespace std;
int N;
int matrix[MAX][MAX];
int ans;
vector<int> bishop;
int vLeft[2*MAX];

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 1) bishop.push_back(i*N+j);
        }
    }
}

void dfs(int n, int cnt){
    // 종료조건
    if(n == 2*N -1){
        if(ans < cnt) ans = cnt;
        return;
    }
    
    int flag = 0;
    for(int cur : bishop){
        int r = cur/N, c = cur%N;
        if(r + c == n && vLeft[r-c+N] == 0) {
            vLeft[r-c+N] = 1;
            dfs(n+1, cnt+1);
            vLeft[r-c+N] = 0;
            flag = 1;
        }
    }
    if(flag == 0) dfs(n+1, cnt);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0);
    cout << ans;
}
