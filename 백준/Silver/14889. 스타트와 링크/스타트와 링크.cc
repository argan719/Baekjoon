#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#define MAX 21
using namespace std;
int N;
int M;
int matrix[MAX][MAX];
int ans = INT_MAX;

int startT[MAX];
int linkT[MAX];

void input(){
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)  // 1번 사람부터 N번 사람
            cin >> matrix[i][j];
    
    M = N/2;
}

int calc(){

    int ssum = 0, lsum = 0;
    for(int i=1; i<=M; i++)
        for(int j=i+1; j<=M; j++) {
            ssum += matrix[startT[i]][startT[j]] + matrix[startT[j]][startT[i]];
            lsum += matrix[linkT[i]][linkT[j]] + matrix[linkT[j]][linkT[i]];
        }
    return abs(ssum - lsum);
}

void dfs(int n, int scnt, int lcnt){
    // 가지치기
    //if(scnt > M || lcnt > M ) return;
    
    if(n == N+1){
        // 정답처리
        if(scnt == M && lcnt == M) {
            int r = calc();
            if(ans > r) ans = r;
        }
        return;
    }
    
    // s팀 가는 경우
    startT[scnt+1] = n;
    dfs(n+1, scnt+1, lcnt);
    // l팀 가는 경우
    linkT[lcnt+1] = n;
    dfs(n+1, scnt, lcnt+1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(1, 0, 0);
    cout << ans;
}