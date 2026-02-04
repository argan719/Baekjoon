#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 12
using namespace std;

int matrix[MAX][MAX];
int R,C;

int dr[] = { -1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

vector<pair<int,int>> down;

void input(){
    string s;
    
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        cin >> s;
        for(int j=0; j<C; j++){
            if(s[j] == '.') matrix[i][j+1] = 0; // 바다
            else if(s[j] == 'X') matrix[i][j+1] = 1; // 땅
        }
    }
}


void solve(){
    int cnt = 0;
    int r_low = R; int r_high = 1;
    int c_low = C; int c_high = 1;
    
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(matrix[i][j] == 1){
                for(int k=0; k<4; k++){
                    if(matrix[i + dr[k]][j + dc[k]] == 0) cnt++;
                }
                if(cnt >= 3) down.push_back(make_pair(i,j));  //matrix[i][j] = 0;
                cnt = 0;
                
            }
        }
    }
    
    for(auto cur : down){
        matrix[cur.first][cur.second] = 0;
    }
    
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(matrix[i][j] == 1){
                r_low = min(r_low, i);
                r_high = max(r_high, i);
                c_low = min(c_low, j);
                c_high = max(c_high, j);
            }
        }
    }
    
    
    // 정답 출력
    for(int i=r_low; i<=r_high; i++){
        for(int j=c_low; j<=c_high; j++){
            if(matrix[i][j] == 0) cout << '.';
            else if(matrix[i][j] == 1) cout << 'X';
        }
        cout << "\n";
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    input();
    
    solve();
}