#include<iostream>
#include<vector>
#include<cstring>
#define MAX 101
using namespace std;

int N, K, TC;
int M;

int num_max[MAX][MAX];
int num[MAX][MAX];
int d[MAX][MAX];

struct g{
    int r, c;
    int num;
    int d;
};
vector<g> units;
int die[1010];  // 해당 군집 죽었는지 여부 표시
// 상 우 하 좌
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int ans;

void input(){
    cin >> N >> M >> K;
    g tmp;
    for(int i=0; i<K; i++){
        cin >> tmp.r >> tmp.c >> tmp.num >> tmp.d;
        // 방향값 바꿔주기
        if(tmp.d == 1) tmp.d = 0;
        else if(tmp.d == 4) tmp.d = 1;
        units.push_back(tmp);
    }
}

void solve(int k){
    memset(num_max, 0, sizeof(num_max));
    memset(d, 0, sizeof(d));
    memset(num, 0, sizeof(num));
    
    // 살아있는 모든 군집 각 이동방향에 맞게 일단 이동
    for(int i=0; i<units.size(); i++){
        if(die[i] == k) continue;
        
        units[i].r += dr[units[i].d];
        units[i].c += dc[units[i].d];
        
        // 만약 셀에 도착했다면
        if(units[i].r == 0 || units[i].r == N-1 || units[i].c == 0 || units[i].c == N-1){
            units[i].num = units[i].num/2;
            
            if(units[i].num == 0) die[i] = k;
            else units[i].d = (units[i].d + 2) % 4;
        }
    }
    
    // 전부 이동후 살아있는 모든 군집에 대해
    for(int i=0; i<units.size(); i++){
        if(die[i] == k) continue;
        int r = units[i].r; int c = units[i].c;
        
        if(num_max[r][c] !=0){
            die[i] = k;
            if(num_max[r][c] < units[i].num) {
                num_max[r][c] = units[i].num;
                d[r][c] = units[i].d;
            }
            num[r][c] += units[i].num;
        }
        else{
            num_max[r][c] = units[i].num;
            d[r][c] = units[i].d;
            num[r][c] = units[i].num;
        }
    }
    
    // 군집 합쳐짐 반영해주기
    for(int i=0; i<units.size(); i++){
        if(die[i] == k) continue;
        
        if(num[units[i].r][units[i].c] > units[i].num){
            units[i].num = num[units[i].r][units[i].c];
            units[i].d = d[units[i].r][units[i].c];
        }
    }
    
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    for(int tc=1; tc<=TC; tc++){
        // TC 별 초기화 작업.
        units.clear();
        //memset(die, 0, sizeof(die));
        
        input();
        for(int m=0; m<M; m++){
            solve(tc);
        }
        // 정답처리
        ans = 0;
        for(int i=0; i<units.size(); i++){
            if(die[i] == tc) continue;
            ans += units[i].num;
        }
        cout << "#" << tc << " " << ans << "\n";
    }
}
