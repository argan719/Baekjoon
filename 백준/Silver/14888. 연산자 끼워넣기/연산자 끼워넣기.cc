#include<iostream>
#define MAX 12
using namespace std;

int arr[MAX];
// +, -, x, / 연산자 갯수 저장
int add, sub, mul, dv;
int N;

int ans_max = -1e9;
int ans_min = 1e9;

void input(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    cin >> add >> sub >> mul >> dv;
}

void dfs(int n, int sum, int add, int sub, int mul, int dv){
    if(n == N){
        // 정답처리
        if(sum > ans_max) ans_max = sum;
        if(sum < ans_min) ans_min = sum;
        
        return;
    }
    
    if(add > 0) dfs(n+1, sum + arr[n], add-1, sub, mul, dv);
    if(sub > 0) dfs(n+1, sum - arr[n], add, sub-1, mul, dv);
    if(mul > 0) dfs(n+1, sum * arr[n], add, sub, mul-1, dv);
    if(dv > 0) dfs(n+1, sum/arr[n], add, sub, mul, dv-1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(1, arr[0], add, sub, mul, dv);  // n, sum, add, sub, mul, div
    cout << ans_max << "\n" << ans_min << "\n";
}