#include<iostream>
#define MAX 11
using namespace std;

int N;
//int arr[MAX][2]; // 신맛, 쓴맛,
struct taste{
    int s, b;
};
taste arr[MAX];
int v[MAX];  // 해당 재료 포함시킴 표시
int ans = 1100000000;

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i].s >> arr[i].b;
    }
}

void dfs(int n, int cnt){
    // 종료조건
    if(n == N){
        // 정답처리
        if(cnt == 0) return;  // 재료가 하나도 선택되지 않은 경우는 제외
        
        int sum_s = 1, sum_b = 0;
        for(int i=0; i<N; i++){
            if(v[i]) {
                sum_s *= arr[i].s;
                sum_b += arr[i].b;
            }
        }
        if(ans > abs(sum_s - sum_b)) ans = abs(sum_s - sum_b);
        return;
    }
    
    // 해당 재료를 포함하는 경우
    v[n] = 1;
    dfs(n+1, cnt+1);
    v[n] = 0;
    // 해당 재료를 미포함하는 경우
    dfs(n+1, cnt);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0);
    cout << ans;
}