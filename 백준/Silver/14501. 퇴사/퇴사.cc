#include<iostream>
#include<algorithm>
#define MAX 20
using namespace std;

int N;
struct date{
    int t=0, p =0;
};

date arr[MAX];
int ans;

void input(){
    cin >> N;
    for(int j=1; j<=N; j++){
        cin >> arr[j].t >> arr[j].p;
    }
}
void dfs(int n, int cost){
    // 종료조건은 이곳에서!!
    if(n > N){
        ans = max(ans, cost);
        return;
    }
    
    // 하부함수 호출
    // 이번에 선택하는 경우
    if(n + arr[n].t -1 <= N) dfs(n+arr[n].t, cost + arr[n].p);
    // 이번에 선택 안 하는 경우 (cost에 영향X)
    dfs(n+1, cost);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    dfs(1, 0);  // n, cost
    cout << ans;
}