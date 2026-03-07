#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 51
using namespace std;

int N, M;
int matrix[MAX][MAX];
int v[15];
int s[15];
int ans = 100 * 2 * 50; // 최솟값

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int CCNT;

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 1) house.push_back({i,j});
            else if(matrix[i][j] == 2) chicken.push_back({i,j});
        }
    }
    CCNT = chicken.size();
}

void check(){
    int dist = 0;
    int min_dist = 100;
    int sum = 0;
    for(auto h : house){
        min_dist = 100;
        for(int i=0; i<M; i++){
            dist = abs(h.first - chicken[s[i]].first) + abs(h.second - chicken[s[i]].second);
            min_dist = min(min_dist, dist);
        }
        sum += min_dist;
    }
    ans = min(ans, sum);
}

void dfs(int n, int start){
    if(n == M){
        // 정답처리
        check();
        return;
    }
    
    for(int j=start; j<CCNT; j++){
        s[n] = j;  // 선택한 치킨집 인덱스
        dfs(n+1, j+1);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0);
    cout << ans;
}