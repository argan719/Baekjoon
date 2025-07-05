#include<iostream>
#include<cstdlib>
#include<queue>
#include<climits>
#define MAX 11
using namespace std;
typedef long long ll;

int N;
ll arr[MAX][2];
int min_val = INT_MAX;
int visited[MAX];
vector<int> vec;

//n : 담은 재료 갯수

void dfs(int n, int cur, ll sum_a, ll sum_b){
    int sum = abs(sum_a - sum_b);
    if(min_val > sum && n > 0) min_val = sum;
    
    if(n == N){
        return;
    }
    
    for(int i=1; i<=N; i++){
        if(visited[i]) continue;
        visited[i] = 1;
        dfs(n+1, i, sum_a*arr[i][0], sum_b+arr[i][1]);
        visited[i] = 0;
        sum_a = 1;
        sum_b = 0;
        n = 0;
    }

}




int main(void){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i][0] >> arr[i][1];  // 신맛 쓴맛
    }
    
    dfs(0, 0, 1, 0);
    cout << min_val;
    
}