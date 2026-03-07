#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 100001
using namespace std;
int T, N;
int arr[MAX]; // 1~N까지
void solve();
int degree[MAX];

void input(){
    cin >> T;
    int val;
    for(int tc=1; tc<=T; tc++){
        cin >> N;
        memset(degree, 0, sizeof(degree));
        for(int i=1; i<=N; i++) {
            cin >> arr[i];  //i가 arr[i]를 선택.
            degree[arr[i]]++;  // 진입차수 계산
        }
        solve();
    }
}

void solve(){
    queue<int> q;
    int cnt = 0;
    
    for(int i=1; i<=N; i++){
        if(degree[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        // 간선차수가 0인것만 큐에 들어가므로
        // 큐에서 나올 때마다 cnt++을 해주면 그게 곧 팀에 못 속한 사람의 수가 된다.
        int cur = q.front();
        q.pop();
        cnt++;
        
        int next = arr[cur];
        degree[next]--;  // 나로부터 나온 간선 제거
        if(degree[next] == 0) q.push(next);
    }
    
    cout << cnt << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
}
