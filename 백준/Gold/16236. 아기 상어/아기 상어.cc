#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
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

struct Fish{
    int r, c;
    int size;
};
//vector<Fish> fish;
int fish_cnt;

int tr, tc;

// 상 좌 우 하
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first) return a.first < b.first;
    
    return a.second < b.second;
}

void input(){
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 9) {
                shark.r = i; shark.c = j; shark.size = 2; shark.cnt = 0;
                // clear 해주기!!!
                matrix[i][j] = 0;
            }
            else if(matrix[i][j] !=0){
                fish_cnt++;
            }
        }
    }
}

int bfs(){
    memset(v, 0, sizeof(v));
    queue<pair<int,int>> q;
    vector<pair<int, int>> tmp;
    //int min_r = 100; int min_c = 100;
    //int step = 1000;
    //int flag = 0;
    int min_step = 0;
    // 단위작업.
    q.push({shark.r, shark.c});
    v[shark.r][shark.c] = 1;  // -1 한 걸 리턴해줘야 step이 됨.
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        // 정답처리는 이곳에서
        if(matrix[cur.first][cur.second] != 0 && matrix[cur.first][cur.second] < shark.size){
            if(min_step == 0){
                min_step = v[cur.first][cur.second] - 1;
                tmp.push_back(cur);
            }
            else{
                if(min_step == v[cur.first][cur.second] - 1) tmp.push_back(cur);
            }
            //tmp.push_back(cur);
            //tr = cur.first; tc = cur.second;
            //step = min(step, v[cur.first][cur.second] - 1);
            //return v[cur.first][cur.second] - 1;
        }
        
        // 연결 4방향
        for(int dir=0; dir<4; dir++){
            int nr = cur.first + dr[dir]; int nc = cur.second + dc[dir];
            if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
            if(v[nr][nc] !=0) continue;
            
            // 못 지나가는 조건
            if(shark.size < matrix[nr][nc]) continue;
            
            q.push({nr,nc});
            v[nr][nc] = v[cur.first][cur.second] + 1;
        }
    }
    if(tmp.size() == 0) return -1;
    
    sort(tmp.begin(), tmp.end(), comp);
    tr = tmp[0].first; tc = tmp[0].second;
    
    return v[tmp[0].first][tmp[0].second] - 1;
}

void solve(){
    int ans = 0;
    while(ans >=0){
        // [0] 종료 조건 확인
        if(fish_cnt == 0) break;
        int cnt = 0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(matrix[i][j] !=0 && matrix[i][j] < shark.size) cnt++;
            }
        }
        if(cnt == 0) break;
        
        // [1] 먹을 수 있는 물고기를 나랑 가까운 곳부터 찾고 - BFS
        tr = 0; tc = 0;
        int step = bfs();
        // 탐색을 했는데 조건에 맞는게 없어서 이동하지 못했다면 종료 (범위 1~N)
        if(step == -1) break;
        
        // [2] bfs를 통해 얻은 tr, tc로 step초가 걸려서 아기 상어 이동
        shark.r = tr; shark.c = tc;
        shark.cnt++;
        fish_cnt--;
        // 자신의 크기와 같은 수의 물고기를 먹을 때마다 크기 1증가 - 이부분 조금 모호함. 디버깅 확인 필요.
        if(shark.cnt == shark.size){
            shark.size++;
            shark.cnt = 0;  // 이걸 clear해주는게 맞는지 아닌지.
        }
        //cout << "잡아먹은 물고기 좌표 : " << tr << " " << tc << "\n";
        //cout << "이번에 이동한 step : " << step << "\n";
        //cout << "그리고 나서 상어 현재 크기 : " << shark.size << "\n";
        // 물고기 자리 clear
        matrix[tr][tc] = 0;
        // time + (이동한 거리 만큼)
        ans += step;
    }
    
    cout << ans << "\n";
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}