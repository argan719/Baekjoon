#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 51
using namespace std;

int N, M;
int matrix[MAX][MAX];
int v[15];
//int s[15];
int ans = 1e5; // 최솟값

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 1) house.push_back({i,j});
            else if(matrix[i][j] == 2) chicken.push_back({i,j});
        }
    }
}

void check(){
    int dist = 0;
    int min_dist = 100;
    int sum = 0;
    
    for(auto h : house){
        min_dist = 100;
        
        for(int i=0; i<chicken.size(); i++){
            if(v[i] == 0) continue;
            dist = abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second);
            min_dist = min(min_dist, dist);
        }
        sum += min_dist;
    }
    ans = min(ans, sum);
}

void dfs(int n, int cnt){
    // 가지치기
    if(cnt > M) return;
    
    if(n == chicken.size()){
        // 정답처리
        if(cnt == M) check();
        return;
    }
    
    // 해당 치킨집을 채택하는 경우
    v[n] = 1;
    dfs(n+1, cnt+1);
    v[n] = 0;
    // 해당 치킨집을 채택하지 않는 경우
    dfs(n+1, cnt);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0);
    cout << ans;
}
