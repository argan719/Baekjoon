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
int v[MAX];

void input(){
    cin >> N;
    for(int j=1; j<=N; j++){
        cin >> arr[j].t >> arr[j].p;
    }
}
void dfs(int start, int n, int cost){
    // 종료조건은 이곳에서!!
    if(start <= N){
        ans = max(ans, cost);
    }
    else{
        cost -= arr[n].p;
        ans = max(ans, cost);
        return;
    }
    
    // 하부함수 호출
    for(int j=start + 1; j<=N; j++){
        if(v[j]) continue;
        //if(j + arr[j].t - 1 > N) continue;
        v[j] = 1;
        dfs(j + arr[j].t - 1, j, cost + arr[j].p);
        v[j] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    dfs(0, 0, 0);  // start, n, cost (start가 종료조건)
    cout << ans;
}