#include<iostream>
#include<cstring>
#include<vector>
#define MAX 11
using namespace std;
int N;
int matrix[MAX][MAX];
int ans;
int vLeft[2*MAX];

vector<pair<int,int>> bishop[2*MAX];

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 1) bishop[i+j].push_back({i, j});
        }
    }
}

void dfs(int n, int cnt){
    //if(ans >= (2*N - 1) - n + cnt) return;
    // 종료조건
    if(n >= 2*N -1){
        if(ans < cnt) ans = cnt;
        return;
    }
    
    int flag = 0;
    for(auto cur : bishop[n]){
        if(vLeft[cur.first - cur.second + N] == 0) {
            vLeft[cur.first - cur.second + N] = 1;
            dfs(n+2, cnt+1);
            vLeft[cur.first - cur.second + N] = 0;
            flag = 1;
        }
    }
    if(flag == 0) dfs(n+2, cnt);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0);
    int result = ans;
    ans = 0;
    dfs(1, 0);
    result += ans;
    cout << result;
}