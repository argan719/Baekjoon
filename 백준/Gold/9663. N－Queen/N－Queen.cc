#include<iostream>
#include<cstring>
#define MAX 15
using namespace std;
int N;
int matrix[MAX][MAX];
int vUp[MAX];
int vLeft[2*MAX];
int vRight[2*MAX];
int ans;

void input(){
    cin >> N;
}

void dfs(int n){
    if(n == N){
        ans++;
        return;
    }
    
    // 하부함수 호출
    for(int j=0; j<N; j++){
        // (열 선택)조건
        if(vUp[j] == 1 || vLeft[n-j+N] == 1 || vRight[n+j] == 1 ) continue;
        
        // 표시
        vUp[j] = 1; vLeft[n-j+N] = 1; vRight[n+j] = 1;
        
        dfs(n+1);
        
        // 원상복구
        vUp[j] = 0; vLeft[n-j+N] = 0; vRight[n+j] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0);
    cout << ans;
}