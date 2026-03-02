#include<iostream>
#include<cstring>
#define MAX 10
using namespace std;

int N;
struct egg{
    int s, w; // 내구도, 무게
};

egg arr[MAX];
//int crack[MAX]; // 깨짐 여부 표시
int ans = 0;

void input(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i].s >> arr[i].w;
}

void dfs(int n, int cnt){
    // 종료조건은 이곳에서
    if(n == N){ // 한번씩 계란을 다 들어봤다면 종료.
        if(ans < cnt) ans = cnt;
        return;
    }
    
    // 하부함수 호출 (중복가능)
    if(arr[n].s <= 0) dfs(n+1, cnt);
    else{
        int flag = 0;
        for(int j=0; j<N; j++){
            if(n == j || arr[j].s <=0 ) continue;
            
            flag = 1;
            arr[n].s -= arr[j].w;
            arr[j].s -= arr[n].w;
            dfs(n+1, cnt+(int)(arr[n].s <= 0)+(int)(arr[j].s <= 0));
            arr[n].s += arr[j].w;
            arr[j].s += arr[n].w;
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
