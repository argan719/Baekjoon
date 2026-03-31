#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 25
using namespace std;

int N, M;
int matrix[MAX][MAX];
int v[MAX][MAX];
int R;  // 레인보우를 편의상 2M으로 설정함.
int ans;

int tmp[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int cnt;
int rcnt;

struct Group{
    int i, j;
    int cnt;
    int rcnt;
    //int my_r; int my_c; // 해당 그룹의 기준 블록
};
vector<Group> group;

bool comp(Group a, Group b){
    if(a.cnt != b.cnt) return a.cnt > b.cnt;
    if(a.rcnt != b.rcnt) return a.rcnt > b.rcnt;
    if(a.i != b.i) return a.i > b.i;
    return a.j > b.j;
    //return a.second > b.second;
}

void input(){
    cin >> N >> M;
    R = 2 * M;
    memset(matrix, -1, sizeof(matrix));  // -1로 패딩.
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 0) matrix[i][j] = R;
        }
    }
}

void bfs(int r, int c){
    //memset(v, 0, sizeof(v));
    queue<pair<int,int>> q;
    q.push({r,c});
    v[r][c] = 1;
    int val = matrix[r][c];
    //cnt++;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        // 정답처리
        cnt++;  // 총 블록의 수 카운트.
        if(matrix[cur.first][cur.second] == R) rcnt++;  // 무지개 블록 수 따로 카운트.
        
        // 상하좌우
        for(int dir=0; dir<4; dir++){
            int nr = cur.first + dr[dir]; int nc = cur.second + dc[dir];
            if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
            if(matrix[nr][nc] == -1) continue;  // 범위내
            if(v[nr][nc] == 1) continue;  // 미방문
            
            // 무지개거나 나랑 값이 같은 일반블록이거나
            if(matrix[nr][nc] == R || matrix[nr][nc] == val){
                q.push({nr,nc});
                v[nr][nc] = 1;
            }
        }
    }
}


void bfs_clear(int r, int c, int flag){
    queue<pair<int,int>> q;
    q.push({r,c});
    v[r][c] = 1;
    int val = matrix[r][c];
    //cnt++;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        // 정답처리 - clear
        if(flag == 1) matrix[cur.first][cur.second] = 0;
        
        
        // 상하좌우
        for(int dir=0; dir<4; dir++){
            int nr = cur.first + dr[dir]; int nc = cur.second + dc[dir];
            if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
            if(matrix[nr][nc] == -1) continue;  // 범위내
            if(v[nr][nc] == 1) continue;  // 미방문
            
            // 무지개거나 나랑 값이 같은 일반블록이거나
            if(matrix[nr][nc] == R || matrix[nr][nc] == val){
                q.push({nr,nc});
                v[nr][nc] = 1;
            }
        }
    }
}


void solve(){
    
    
    while(1){
        // [1] 크기가 가장 큰 블록그룹 찾기
        int cnt_max = 2;  // 그룹에 속한 블록의 개수는 2보다 크거나 같아야 하며.
        int rcnt_max = 0;
        group.clear();
        
        memset(v, 0, sizeof(v));
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(matrix[i][j] < 1) continue;
                //if(v[i][j] == 1) continue;
                if(matrix[i][j] == R) continue;
                
                // 무조건 미방문 일반 색상일때만 bfs하는 걸로 하자.
                cnt = 0; rcnt = 0;
                bfs(i,j);
                if(cnt_max <= cnt){
                    cnt_max = cnt;
                    //cout << "group push_back " << i << j << endl;
                    group.push_back({i,j, cnt, rcnt});
                    if(rcnt_max <= rcnt) rcnt_max = rcnt;
                }
                
                for(int i=1; i<=N; i++){
                    for(int j=1; j<=N; j++){
                        if(v[i][j] == 1 && matrix[i][j] == R) v[i][j] = 0;
                    }
                }
            }
        }
        //cout << "cnt_max : " << cnt_max << endl;
        // 탈출 조건.
        if(cnt == 0 || group.size() == 0) break;
        
        vector<pair<int,int>> tg;
        vector<pair<int,int>> rc;
        //int max_i = 0; int max_j = 0;
        int r = 0; int c = 0;
//        for(auto n : group){
//            if(n.cnt == cnt_max){
//
//                cout << "tg push_back " << n.i << " " << n.j << endl;
//                tg.push_back({n.i, n.j});
//            }
//        }
        //if(tg.size() == 0) cout << "tg사이즈0"<< endl;
//        if(tg.size() != 0) {
//            sort(tg.begin(), tg.end(), comp);
//            r = tg[0].first;
//            c = tg[0].second;
//        }
//        tg.clear();
        
        sort(group.begin(), group.end(), comp);
        r = group[0].i;
        c = group[0].j;
        //cout << " r c " << r << " " << c << endl;
        
        // [2] 해당 그룹 블록 clear
        memset(v, 0, sizeof(v));
        ans += cnt_max * cnt_max;
        bfs_clear(r,c, 1);
        
//        cout << "clear 후" << endl;
//        for(int i=1; i<=N; i++){
//            for(int j=1; j<=N; j++){
//                cout << matrix[i][j] << " " ;
//            }
//            cout << endl;
//        }
        
        //cout << "ans : " << ans << "\n";
        //cout << " r c " << r << " " << c << "\n";
        
        
        // [3] 첫번째 중력 작용
        for(int j=1; j<=N; j++){
            for(int i=N-1; i>=1; i--){
                if(matrix[i][j] < 1) continue;
                
                //cout << "i j 가 내려간다 : " << i << " " << j << endl;
                for(int bottom = i+1; bottom <= N+1; bottom++){
                    //cout << bottom << endl;
                    if(matrix[bottom][j] != 0) {
                        //cout << "여기에서 0아닌 걸 발견" << bottom-1 << endl;
                        matrix[bottom-1][j] = matrix[i][j];
                        if(bottom - 1 != i) matrix[i][j] = 0;
                        break;
                    }
                }
            }
        }
        
//        cout << "중력 후" << endl;
//        for(int i=1; i<=N; i++){
//            for(int j=1; j<=N; j++){
//                cout << matrix[i][j] << " ";
//            }
//            cout << "\n";
//        }
        
        // [4] 90도 반시계 회전
        memset(tmp, 0, sizeof(tmp));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                tmp[1 + i][1 + j] = matrix[1 + j][1 + N - 1 - i];
            }
        }
        memset(matrix, -1, sizeof(matrix));
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                matrix[i][j] = tmp[i][j];
            }
        }
        
        
        // [5] 마지막 두번째 중력 작용
        for(int j=1; j<=N; j++){
            for(int i=N-1; i>=1; i--){
                if(matrix[i][j] < 1) continue;
                
                //cout << "i j 가 내려간다 : " << i << " " << j << endl;
                for(int bottom = i+1; bottom <= N+1; bottom++){
                    //cout << bottom << endl;
                    if(matrix[bottom][j] != 0) {
                        //cout << "여기에서 0아닌 걸 발견" << bottom-1 << endl;
                        matrix[bottom-1][j] = matrix[i][j];
                        if(bottom - 1 != i) matrix[i][j] = 0;
                        break;
                    }
                }
            }
        }
        
//        cout << endl;
//        cout << "마지막 중력 작용 후" << endl;
//        for(int i=1; i<=N; i++){
//            for(int j=1; j<=N; j++){
//                cout << matrix[i][j] << " ";
//            }
//            cout << "\n";
//        }
        
    }
    cout << ans <<"\n";
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}
