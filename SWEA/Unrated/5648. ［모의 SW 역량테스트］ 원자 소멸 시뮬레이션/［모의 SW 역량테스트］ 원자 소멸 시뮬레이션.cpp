#include<iostream>
#include<vector>
#include<cstring>
#include<set>
#define MAX 4001
using namespace std;

int N, TC;
int v[MAX][MAX];
int d[MAX][MAX];
long long TURN;

struct ATOM{
    int x, y;
    int d;
    int k;
};
vector<ATOM> units;

//set<pair<int,int>> del;

// 상 하 좌 우
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

int ans;

void solve(){
    //memset(v, 0, sizeof(v));
    //del.clear();
    
    for(int k=1; k<=4000; k++){
        TURN++;
        
        for(int i=0; i<units.size(); ){
            units[i].x += dc[units[i].d];
            units[i].y += dr[units[i].d];
            
            if(units[i].x < 0 || units[i].x > 4000 || units[i].y < 0 || units[i].y > 4000) units.erase(units.begin() + i);
            
            else i++;
        }
        
        for(auto cur : units){
            if(v[cur.x][cur.y] == TURN){
                //cout << "del " << endl;
                //del.insert({cur.x, cur.y});
                d[cur.x][cur.y] = TURN;
            }
            else v[cur.x][cur.y] = TURN;
        }
        
        for(int i=0; i<units.size();){
            if(d[units[i].x][units[i].y] == TURN){
                //cout << "ans : " << ans << "\n";
                ans += units[i].k;
                units.erase(units.begin() + i);
            }
            else i++;
        }
        
    }
}

void input(){
    cin >> TC;
    ATOM tmp;
    for(int tc=1; tc<=TC; tc++){
        cin >> N;
        units.clear();
        for(int i=0; i<N; i++){
            cin >> tmp.x >> tmp.y >> tmp.d >> tmp.k;
            // 0부터 4000까지
            //tmp.x += 1000; tmp.y += 1000;
            tmp.x *= 2; tmp.y *= 2;
            tmp.x += 2000; tmp.y += 2000;
            units.push_back(tmp);
        }
        ans = 0;
        solve();
        cout << "#" << tc << " " << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    //solve();
}