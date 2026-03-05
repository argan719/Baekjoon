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
int v[MAX];  // 1이면 스타트팀, 2이면 링크팀

void input(){
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)  // 1번 사람부터 N번 사람
            cin >> matrix[i][j];
    
    M = N/2;
}

int calc(){
    vector<int> startT; // 스타트팀
    vector<int> linkT;  // 링크팀
    
    for(int i=1; i<=N; i++){
        if(v[i] == 1) startT.push_back(i);
        else if(v[i] == 2) linkT.push_back(i);
    }
    
    int ssum = 0, lsum = 0;
    for(int i=0; i<startT.size(); i++)
        for(int j=i+1; j<startT.size(); j++)
            ssum += matrix[startT[i]][startT[j]] + matrix[startT[j]][startT[i]];
    
    for(int i=0; i<linkT.size(); i++)
        for(int j=i+1; j<linkT.size(); j++)
            lsum += matrix[linkT[i]][linkT[j]] + matrix[linkT[j]][linkT[i]];
    
    return abs(ssum - lsum);
}

void dfs(int n, int scnt, int lcnt){
    // 가지치기
    if(scnt > M || lcnt > M ) return;
    
    if(n == N+1){
        // 정답처리
        if(scnt == M && lcnt == M) {
            int r = calc();
            if(ans > r) ans = r;
        }
        return;
    }
    
    // s팀 가는 경우
    v[n] = 1;
    dfs(n+1, scnt+1, lcnt);
    v[n] = 0;
    // l팀 가는 경우
    v[n] = 2;
    dfs(n+1, scnt, lcnt+1);
    v[n] = 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(1, 0, 0);
    cout << ans;
}
