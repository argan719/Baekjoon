#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 51
using namespace std;

int N, M;
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;

int arr[15];
int ans = 50000;

void input(){
    cin >> N >> M;
    int val;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> val;
            if(val == 1) house.push_back({i,j});
            else if(val == 2) chicken.push_back({i,j});
        }
    }
}

void dfs(int n, int start){
    if(n == M){
        // 정답처리
        int sum = 0;
        for(auto h : house){
            int min_dist = 300;
            for(int c=0; c<chicken.size(); c++){
                if(arr[c] == 0) continue;
                
                min_dist = min(min_dist, abs(chicken[c].first - h.first) + abs(chicken[c].second - h.second));
            }
            sum += min_dist;
        }
        ans = min(ans, sum);
        
        return;
    }
    
    for(int i=start; i<chicken.size(); i++){
        arr[i] = 1;
        dfs(n+1, i+1);
        arr[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0);
    cout << ans;
}
