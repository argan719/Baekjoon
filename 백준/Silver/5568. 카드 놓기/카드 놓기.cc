#include<iostream>
#include<set>
#include<cmath>
#define MAX 11
using namespace std;

int arr[MAX];
int result[MAX];
int visited[MAX];
int N, K;
set<int> s;

// n: 선택된 숫자 개수
void dfs(int n, int cur){
    int sum;
    int k;
    int cnt;
    
    result[n] = cur;
    // 정답 처리
    if(n == K){
        sum = 0;
        k = K;
        cnt = 0;
        
        while(n>=1){
            sum += result[n] * pow(10, cnt++);
            if(result[n] >= 10) cnt++;
            n--;
        }
        s.insert(sum);
        sum = 0;
        return;
    }
    
    //앞에서 푼 모든 순열 문제와 동일
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(n+1, arr[i]);
            visited[i] = 0;
        }
    }
    
}

int main(void){
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    dfs(0, 0);
    cout << s.size();
}