#include<iostream>
#include<algorithm>
#define MAX 10
using namespace std;

int arr[MAX];
int ans[MAX];
int N, M;
void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N); // 오름차순 정렬
}

void dfs(int n, int start){
    // 종료조건은 여기에서
    if(n == M){
        for(int j=0; j<M; j++) cout << ans[j] << " ";
        cout << "\n";
    }
    
    // 하부함수 호출
    for(int j=start; j<N; j++){
        ans[n] = arr[j];
        dfs(n+1, j+1);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0);
}