#include<iostream>
#include<vector>
#include<cmath>
#define MAX_VAL 300000
#define MAX 51
using namespace std;

struct pos{
    int x,y;
};
vector<pos> house;
int v[MAX];  // 대피소 표시
int N, K;
int ans = MAX_VAL;


void input(){
    cin >> N >> K;
    pos tmp;
    for(int i=0; i<N; i++){
        cin >> tmp.x >> tmp.y;
        house.push_back(tmp);
    }
}

void calc(){
    vector<pos> safe;  // 대피소 좌표
    vector<pos> home;  // 대피소가 아닌 나머지 집들 좌표
    for(int i=0; i<N; i++)
    {
        if(v[i]) safe.push_back(house[i]);
        else home.push_back(house[i]);
    }
    
    int max_dist = 0;
    for(pos h : home){
        int dist = MAX_VAL;
        for(pos s : safe){
            if(dist > abs(h.x-s.x) + abs(h.y-s.y)) dist = abs(h.x-s.x) + abs(h.y-s.y);
        }
        if(max_dist < dist) max_dist = dist;
    }
    if(ans > max_dist) ans = max_dist;
}

void dfs(int n, int start){
    if(n == K){
        // 정답처리
        calc();
        return;
    }
    
    for(int j=start; j<N; j++){
        if(v[j]) continue;
        v[j] = 1; // 대피소 표시
        dfs(n+1, j+1);
        v[j] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0);
    cout << ans;
}
