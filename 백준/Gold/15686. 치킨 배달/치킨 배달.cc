#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX 51
using namespace std;

int N, M;
int matrix[MAX][MAX];
int v[MAX];

struct Pos{
    int r, c;
};
vector<Pos> house;
vector<Pos> chicken;

int mlst[15]; // 선정한 치킨집. 0~M-1
int ans = 1e5;

void input(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 0) continue;
            if(matrix[i][j] == 1) house.push_back({i,j});  // 집 좌표
            else if(matrix[i][j] == 2) chicken.push_back({i,j}); // 치킨집 좌표
        }
    }
}

void dfs(int n, int start){
    // 종료조건은 이곳에서
    if(n == M){
        // 치킨거리의 합 구해서 최솟값 갱신.
        int sum = 0;
        for(auto h : house){
            int house_min = 1000;
            for(int i=0; i<M; i++){
                house_min = min(house_min, abs(chicken[mlst[i]].r - h.r) + abs(chicken[mlst[i]].c - h.c));
            }
            sum += house_min;
        }
        ans = min(ans, sum);
        return;
    }
    
    for(int i=start; i<chicken.size(); i++){
        //if(v[i]) continue;
        //v[i] = 1;
        mlst[n] = i;
        dfs(n+1, i+1);
        //v[i] = 0;
    }
}


int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0);
    cout << ans;
}
