#include<iostream>
#define MAX 11
using namespace std;

int N;
struct taste{
    int s, b;
};
taste arr[MAX];
//int v[MAX];  // 해당 재료 포함시킴 표시
int ans = (int)1e9;

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i].s >> arr[i].b;
    }
}

void dfs(int n, int mul, int sum, int cnt){
    // 종료조건
    if(n == N){
        // 정답처리
        if(cnt == 0) return;  // 재료가 하나도 선택되지 않은 경우는 제외
        
        if(ans > abs(mul - sum)) ans = abs(mul - sum);
        return;
    }
    
    // 해당 재료를 포함하는 경우
    dfs(n+1, mul * arr[n].s, sum + arr[n].b, cnt+1);
    // 해당 재료를 미포함하는 경우
    dfs(n+1, mul, sum, cnt);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 1, 0, 0);  // n, mul, sum, cnt
    cout << ans;
}
