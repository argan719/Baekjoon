#include<iostream>
#define MAX 12
using namespace std;

int arr[4];  // +, -, x, / 연산자 갯수 저장
int num[MAX];
int N, M;
int ans[MAX];

int max_ans = -1e9;
int min_ans = 1e9;

void input(){
    cin >> N;
    M = N - 1;
    for(int i=0; i<N; i++) cin >> num[i];
    for(int i=0; i<4; i++) cin >> arr[i];
}

void dfs(int n){
    if(n == M){
        // 정답처리
        int sum = 0;
        int tmp[MAX] = {0, };
        for(int i=0; i<N; i++) tmp[i] = num[i];
        
        for(int i=0; i<N-1; i++){
            if(ans[i] == 0){
                sum = tmp[i] + tmp[i+1];
            }
            else if(ans[i] == 1){
                sum = tmp[i] - tmp[i+1];
            }
            else if(ans[i] == 2){
                sum = tmp[i] * tmp[i+1];
            }
            else if(ans[i] == 3){
                if(tmp[i] < 0) {
                    sum = (abs(tmp[i])/tmp[i+1]) * -1;
                }
                else sum = tmp[i]/tmp[i+1];
            }
            tmp[i+1] = sum;
        }
        if(sum > max_ans) max_ans = sum;
        if(sum < min_ans) min_ans = sum;
        
        return;
    }
    
    for(int j=0; j<4; j++){
        if(arr[j] <= 0) continue;
        arr[j]--;
        ans[n] = j;
        dfs(n+1);
        arr[j]++;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0);
    cout << max_ans << "\n" << min_ans << "\n";
}
