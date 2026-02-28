#include<iostream>
#include<cstring>
#define MAX 10
using namespace std;

int N;
struct egg{
    int s, w; // 내구도, 무게
};

egg arr[MAX];
int crack[MAX]; // 깨짐 여부 표시
int ans = 0;

void input(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i].s >> arr[i].w;
}

void check(int n, int target){
    arr[n].s -= arr[target].w; arr[target].s -= arr[n].w;
    if(arr[n].s <=0) crack[n] = 1;
    if(arr[target].s <=0) crack[target] = 1;
}

void restore(int n, int target){
    arr[n].s += arr[target].w; arr[target].s += arr[n].w;
    if(arr[n].s > 0) crack[n] = 0;
    if(arr[target].s > 0) crack[target] = 0;
}

void dfs(int n, int cnt){
    // 종료조건은 이곳에서
    if(n == N){ // 한번씩 계란을 다 들어봤다면 종료.
        if(ans < cnt) ans = cnt;
        return;
    }
    
    // 하부함수 호출 (중복가능)
    if(crack[n] == 1) dfs(n+1, cnt);
    else{
        int flag = 0;
        for(int j=0; j<N; j++){
            if(n == j) continue;
            
            if(crack[j] == 0) {
                flag = 1;
                check(n, j);
                dfs(n+1, cnt+crack[n]+crack[j]);
                restore(n, j);
            }
        }
        if(flag == 0) dfs(n+1, cnt);
    }
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0);
    cout << ans;
}