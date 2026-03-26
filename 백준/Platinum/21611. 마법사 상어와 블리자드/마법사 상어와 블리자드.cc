#include<iostream>
#include<cstring>
#include<vector>
#define MAX 50
using namespace std;

int N, M;
int matrix[MAX][MAX];
//int tmp[MAX][MAX];
int transform[MAX][MAX];

struct Magic{
    int d;
    int s;
};
vector<Magic> magic;
int lookup[5] = {0, 0, 2, 1, 3}; // 1,2,3,4 로 방향 정보가 들어오면 변환해줌.

int cr, cc;  // 상어 있는 좌표
// 상 좌 하 우
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

struct Pos{
    int r, c;
};
vector<Pos> pos;

struct Marble{
    int r, c;
    int num; // 해당 구슬의 번호.
};

//int ans1, ans2, ans3;
int ans[4]; // 폭발한 1번, 2번, 3번 구슬 개수

void input(){
    cin >> N >> M;
    Magic tmp;
    cr = N/2;
    cc = N/2;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
        }
    }
    for(int i=0; i<M; i++){
        cin >> tmp.d >> tmp.s;
        tmp.d = lookup[tmp.d];
        magic.push_back(tmp);
    }
    
    // 나선형 좌표. 상어 다음 좌표부터 시작해서 0,0까지 미리 담아놓기.
    int r = cr; int c = cc;
    int flag = 0; int cnt = 0; int len = 1; int d = 1;
    while(1){
        r = r + dr[d]; c = c + dc[d]; cnt++;
        if(cnt == len){
            if(flag == 0) {cnt = 0; flag = 1;}
            else if(flag == 1) {cnt = 0; flag = 0; len++;}
            d = (d+1) %4;
        }
        pos.push_back({r, c});
        if(r == 0 && c == 0) break;
    }
    
//    for(auto n : pos){
//        cout << n.r << " " << n.c << "\n";
//    }
}


void solve(){
    vector<Marble> marble;
    vector<Marble> tmp;
    
    
    for(int m=0; m<magic.size(); m++){
        // [1] 파괴 - 블리자드 마법 시전
        for(int s=1; s<=magic[m].s; s++){
            int nr = cr + dr[magic[m].d] * s;
            int nc = cc + dc[magic[m].d] * s;
            
            if(nr < 0 || nr >= N || nc < 0 || nc >=N) continue;
            matrix[nr][nc] = 0;
        }

        // [2] 이동
        // [3] 폭발 - 폭발한 구슬 종류 및 개수 카운트 필요.
        while(1){
            marble.clear();
            tmp.clear();
            
            // 0이 아닌 좌표들을 전부 marble에 담기.
            for(auto cur : pos){
                if(matrix[cur.r][cur.c] != 0) marble.push_back({cur.r, cur.c, matrix[cur.r][cur.c]});
            }
            
            // 구슬들을 돌면서 4개 이상 연속할 때 matrix를 0으로 만들기.
            Marble start;
            int flag = 0;
            // 전부 0이라면?? marble에 하나도 안 담긴다면. 구슬이 하나도 없는 경우이므로 그대로 종료해도 무방.
            if(marble.size() == 0) return;
            start = marble[0];
            //tmp.push_back(start);
            int same = 0;
            
            for(auto cur : marble){
                if(cur.num == start.num){
                    same++;
                    tmp.push_back(cur);
                }
                else{
                    if(same >=4){
                        flag = 1;
                        for(auto n : tmp) {
                            ans[matrix[n.r][n.c]]++;
                            matrix[n.r][n.c] = 0;
                        }
                    }
                    same = 1;
                    start = cur;
                    tmp.clear();
                    tmp.push_back(start);
                }
            }
            if(same >=4){
                flag = 1;
                for(auto n : tmp) {
                    ans[matrix[n.r][n.c]]++;
                    matrix[n.r][n.c] = 0;
                }
            }
            tmp.clear();
            if(flag == 0) break;
        }
        
        marble.clear();
        // 0이 아닌 좌표들을 전부 marble에 담기.
        for(auto cur : pos){
            if(matrix[cur.r][cur.c] != 0) marble.push_back({cur.r, cur.c, matrix[cur.r][cur.c]});
        }
        // 전부 0이라면?? marble에 하나도 안 담긴다면. 구슬이 하나도 없는 경우이므로 그대로 종료해도 무방.
        if(marble.size() == 0) return;
        
        // [4] 변화
        memset(matrix, 0, sizeof(matrix));
        Marble start;
        start = marble[0];
        int same = 0;
        int idx = 0;
        for(auto cur : marble){
            if(cur.num == start.num){
                same++;
            }
            else{
                if(idx >= pos.size()) break;
                matrix[pos[idx].r][pos[idx].c] = same; idx++;
                if(idx >= pos.size()) break;
                matrix[pos[idx].r][pos[idx].c] = start.num; idx++;
                //cout <<  "start.num " << start.num << "\n";
                same = 1;
                start = cur;
            }
        }
        if(idx < pos.size()){
            matrix[pos[idx].r][pos[idx].c] = same;
            idx++;
            if(idx < pos.size()) matrix[pos[idx].r][pos[idx].c] = start.num;
        }
        
//        cout << "TRANSFORM" << endl;
//        for(int i=0; i<N; i++){
//            for(int j=0; j<N;j++){
//                cout << matrix[i][j] <<  " ";
//            }
//            cout << "\n";
//        }
        
    }
    
    
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
    cout << (1 * ans[1]) + (2 * ans[2]) + (3 * ans[3]) << "\n";
}