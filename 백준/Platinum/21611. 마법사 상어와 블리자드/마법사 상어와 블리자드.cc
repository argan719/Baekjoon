#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
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

//struct Marble{
//    int r, c;
//    int num; // 해당 구슬의 번호.
//};

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
    
}


void solve(){
    vector<int> marble;
    vector<int> new_marble;
    vector<int> transform;
    
    for(int m=0; m<magic.size(); m++){
        // [1] 파괴 - 블리자드 마법 시전
        for(int mul=1; mul<=magic[m].s; mul++){
            int nr = cr + dr[magic[m].d] * mul;
            int nc = cc + dc[magic[m].d] * mul;
            
            if(nr < 0 || nr >= N || nc < 0 || nc >=N) continue;
            matrix[nr][nc] = 0;
        }
        
        // pos 순서로 matrix를 돌면서 0이 아닌 구슬들만 모은다.
        for(auto n : pos){
            if(matrix[n.r][n.c] > 0) marble.push_back(matrix[n.r][n.c]);
        }
        
        // [2] - [3] 이동과 폭발 반복.
        // marble을 가지고 4개 연속 확인 후
        // explode에 4개 연속을 전부 지운 구슬들을 넣고 그걸 다시 marble에 넣고 .. 반복.
        int flag = 0;
        while(1){
            // 맨 마지막에 패딩으로 -1을 넣어준다.
            marble.push_back(-1);
            new_marble.clear();
            flag = 0;
            
            int s = 0; int e = 0;
            while(s < marble.size() - 1){
                e = s + 1;
                while(marble[s] == marble[e]){
                    e++;
                }
                if(e - s >= 4) {
                    flag = 1;
                    // 정답처리
                    for(int i=s; i<e; i++) {
                        ans[marble[i]]++;
                    }
                }
                else if(e - s < 4){
                    for(int i=s; i<e; i++) new_marble.push_back(marble[i]);
                }
                s = e;
            }
            marble.clear();  // -1이 있으므로 걍 클리어 후 새로 대입.
            marble = new_marble;
            //marble.push_back(-1);
            //new_marble.clear();  // 이것도 반드시 클리어 필요.
            
            //cout << flag << "\n";
            // 4개 연속이 없었다면 더 이상 반복하지 않으므로 탈출.
            if(flag == 0) break;
        }
        
        // [4] 변화
        // marble을 가지고 A, B를 구해서 matrix를 새롭게 만들어야 하는 것
        marble.push_back(-1);
        
        int s = 0; int e = 0;
        while(s < marble.size() - 1){
            e = s + 1;
            while(marble[s] == marble[e]){
                e++;
            }
            transform.push_back(e-s);  // A삽입
            transform.push_back(marble[s]); // B삽입
            s = e;
        }
        
        while(transform.size() < pos.size()){
            transform.push_back(0);  // 0으로 동일하게 채워줘서 pos 기준으로 matrix에 채워넣기.
        }
        
        memset(matrix, 0, sizeof(matrix));
        for(int i=0; i<pos.size(); i++){
            matrix[pos[i].r][pos[i].c] = transform[i];
        }
        transform.clear();
        marble.clear();
    }
    
    
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
    cout << (1 * ans[1]) + (2 * ans[2]) + (3 * ans[3]) << "\n";
}