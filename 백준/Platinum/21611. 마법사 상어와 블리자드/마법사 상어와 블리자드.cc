#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAX 50
using namespace std;

int N, M;
int matrix[MAX][MAX];

struct Magic{
    int d, s;
};

struct Pos{
    int r,c;
};

vector<Magic> magic;
vector<Pos> pos;

Pos shark;

int ans[4];  // [1] = 폭발한 1번 구슬의 개수, [2] = 폭발한 2번 구슬의 개수, [3] = ""

int dr[] = {0, 1, 0, -1};
int dc[] = {-1, 0, 1, 0};

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
        }
    }
    int d, s;
    for(int i=0; i<M; i++){
        cin >> d >> s;
        magic.push_back({d,s});
    }
    
    int cnt = 0; int flag = 0; int len = 1;
    shark.r = N/2; shark.c = N/2;
    int r = N/2; int c = N/2;
    d = 0;
    
    while(1){
        int nr = r + dr[d]; int nc = c + dc[d];
        pos.push_back({nr, nc});
        //cout << nr << " " << nc << endl;
        cnt++;
        
        if(cnt == len){
            cnt = 0;
            d = (d+1)%4;
            
            if(flag == 0) flag = 1;
            else{
                len++; flag = 0;
            }
        }
        
        r = nr; c = nc;
        
        if(nr == 0 && nc == 0) break;
    }

}

void solve(){
    
    for(Magic m : magic){
        if(m.d == 3) m.d = 0;
        else if(m.d == 2) m.d = 1;
        else if(m.d == 4) m.d = 2;
        else if(m.d == 1) m.d = 3;
        
        
        //[1] 구슬 파괴
        for(int mul = 1; mul <= m.s; mul++){
            int nr = shark.r + dr[m.d] * mul;
            int nc = shark.c + dc[m.d] * mul;
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            matrix[nr][nc] = 0;
        }
        
        // 구슬 이동 <-> 폭발 반복: 4개 이상 연속하는 구슬이 없을 때까지
        vector<int> marble;
        for(auto n : pos){
            if(matrix[n.r][n.c] != 0) marble.push_back(matrix[n.r][n.c]);
        }
        marble.push_back(-1);
        
        while(1){
            vector<int> tmp;
            int flag = 0;
            
            int s = 0; int cnt = 0;
            for(int e=0; e<marble.size(); e++){
                
                if(marble[s] != marble[e]){
                    if(e - s < 4) {
                        while(s != e) {
                            tmp.push_back(marble[s]); s++;
                        }
                    }
                    else if(e - s >=4) {
                        flag = 1;
                        while(s != e) {
                            ans[marble[s]]++; s++;
                        }
                    }
                }
            }
            marble.clear();
            marble = tmp;
            tmp.clear();
            marble.push_back(-1);
            
            if(flag == 0) break;
        }
        
        
        //[4] 구슬 변화
        memset(matrix, 0, sizeof(matrix));
        vector<int> tmp;
        int s = 0; int cnt = 0;
        for(int e=0; e<marble.size(); e++){
            if(marble[s] != marble[e]){
                tmp.push_back(e-s);
                tmp.push_back(marble[s]);
                s = e;
            }
        }
        
        int size = min(tmp.size(), pos.size());
        for(int i=0; i<size; i++){
            matrix[pos[i].r][pos[i].c] = tmp[i];
        }
        
        
//        cout << "구슬 변화 확인 \n";
//        for(int i=0; i<N; i++){
//            for(int j=0; j<N; j++){
//                cout << matrix[i][j] << " " ;
//            }
//            cout << endl;
//        }
        
    }
    cout << 1* ans[1] + 2*ans[2] + 3*ans[3];
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}