#include<iostream>
#include<cstring>
#define MAX 15
using namespace std;

int K;
int arr[MAX];
//int v[MAX];
int ans[MAX];

void dfs(int n, int start){
    // 종료조건
    if(n == 6){
        for(int i=0; i<6; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    
    // 하부 함수 호출
    for(int j=start; j<K; j++){
        ans[n] = arr[j];
        dfs(n+1, j+1);
    }
}

void input(){
    while(1){
        memset(arr, 0, sizeof(arr));
        //memeset(v, 0, sizeof(v));
        memset(ans, 0, sizeof(ans));
        
        cin >> K;
        if(K == 0) break;
        for(int i=0; i<K; i++) cin >> arr[i];
        dfs(0, 0);
        cout << "\n"; // 각 테스트케이스 사이에는 빈 줄을 하나 출력한다.
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    //dfs(0);
}
