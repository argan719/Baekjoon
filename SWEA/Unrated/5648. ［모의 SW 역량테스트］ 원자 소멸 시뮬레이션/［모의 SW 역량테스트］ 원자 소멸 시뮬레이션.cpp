#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int TC, N;
struct atom{
    int j, i;
    int k, d;
};

vector<atom> units;
int v[4100][4100];
int del[4100][4100];
long long TURN;
// 상하좌우
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};
int ans;

void solve(){
    
    for(int k=1; k<=4000; k++){
        //memset(del, 0, sizeof(del));
        //memset(v, 0, sizeof(v));
        TURN++;
        
        // 모든 원소 (0.5*2)씩 이동
        for(auto& cur : units){
            //cout << "이동전 " << cur.j << " " << cur.i << endl;
            cur.j += dc[cur.d];
            cur.i += dr[cur.d];
            //cout << "이동후 " << cur.j << " " << cur.i << endl;
        }
        
        int tmp_j, tmp_i;
        for(auto cur : units){
            if(cur.j < 0 || cur.j > 4000 || cur.i < 0 || cur.i > 4000) continue;
            if(v[cur.j][cur.i] == TURN){
                //del.insert({cur.j, cur.i});
                del[cur.j][cur.i] = TURN;
                //del.push_back({cur.j, cur.i});
            }
            //cout << cur.j << " " << cur.i << "\n";
            else v[cur.j][cur.i] = TURN;
        }
        
        for(int i=0; i<units.size();){
            if(units[i].j < 0 || units[i].j > 4000 || units[i].i < 0 || units[i].i > 4000){
                units.erase(units.begin() + i);
            }
            else if(del[units[i].j][units[i].i] == TURN) {
                //cout << "ans " << ans << "\n";
                ans += units[i].k;
                units.erase(units.begin() + i);
            }
            else i++;
        }
    }
    
}

void input(){
    cin >> TC;
    atom tmp;
    
    for(int tc=1; tc<=TC; tc++){
        cin >> N;
        units.clear();
        //memset(v, 0, sizeof(v));
        //memset(del, 0, sizeof(del));
        ans = 0;
        
        for(int i=0; i<N; i++){
            cin >> tmp.j >> tmp.i >> tmp.d >> tmp.k;
            tmp.j += 1000; tmp.i += 1000;
            tmp.j *= 2; tmp.i *= 2;   // 0 ~ 4000
            units.push_back(tmp);
        }
        
        solve();
        
        cout << "#" << tc << " " << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
}
