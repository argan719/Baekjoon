// 2. 점수 처리하며 가는 방법
#include<iostream>
#define MAX 11
using namespace std;

int arr[MAX]; // 문제의 정답
//int ans[MAX];
int cnt; // 정답이 되는 경우의 수

void input(){
    for(int i=1; i<=10; i++) cin >> arr[i];  // 1~10문제
}

void dfs(int n, int pprev, int prev, int score){
    // 종료조건
    if(n == 11){
        // 정답처리
        if(score >= 5) cnt++;
        return;
    }
    // 하부 함수 호출 - 5지선다
    for(int j=1; j<=5; j++){
        if(pprev == prev && prev == j) continue;  // 3연속 제외

        // 정답을 맞춘 경우
        if(j == arr[n]) dfs(n+1, prev, j, score+1);
        else dfs(n+1, prev, j, score);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(1, 0, 0, 0);  // score 추가
    cout << cnt;
}