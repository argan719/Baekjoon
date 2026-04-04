#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#define MAX 21
using namespace std;

int N;
int matrix[MAX][MAX];
int v[MAX][MAX];

struct Shark{
    int r, c;
    int size;
    int cnt;
};
Shark shark;

struct pos{
    int r,c;
};
vector<pos> fish;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int ans;

bool comp(pos a, pos b){
    if(a.r != b.r) return a.r < b.r;
    return a.c < b.c;
}

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 9){
                matrix[i][j] = 0;
                shark.r = i; shark.c = j; shark.size = 2; shark.cnt = 0;
            }
        }
    }
}

int bfs(){
    fish.clear();
    memset(v, 0, sizeof(v));
    
    queue<pos> q;
    q.push({shark.r, shark.c});
    v[shark.r][shark.c] = 1;
    int flag = 0;
    int step = 0;
    
    while(!q.empty()){
        int len = q.size();
        
        for(int i=0; i<len; i++){
            auto cur = q.front();
            q.pop();
            
            // 정답 처리는 이곳에서
            if(matrix[cur.r][cur.c] !=0 && matrix[cur.r][cur.c] < shark.size) {
                flag = 1;
                fish.push_back({cur.r, cur.c});
            }
            
            for(int dir=0; dir<4; dir++){
                int nr = cur.r + dr[dir]; int nc = cur.c + dc[dir];
                if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                if(v[nr][nc] !=0) continue;
                
                if(matrix[nr][nc] > shark.size) continue;
                q.push({nr,nc});
                v[nr][nc] = 1;
            }
        }
        if(flag == 1) return step;
        step++;
    }
    //cout << "step : " << step << endl;
    return -1;
}

void solve(){
    
    while(1){
        // [1] BFS - 이동할 곳 선정
        int step = bfs();
        if(step == -1) break;
        if(fish.size() == 0) break;  // 더 이상 먹을 수 있는 물고기가 공간에 없는 경우.
        
        ans += step;

        sort(fish.begin(), fish.end(), comp);
        // 선정한 곳으로 이동 및 정답처리
        shark.r = fish[0].r;
        shark.c = fish[0].c;
        matrix[shark.r][shark.c] = 0;
        
        shark.cnt++;
        if(shark.cnt == shark.size){
            shark.cnt = 0;
            shark.size++;
        }
        
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}