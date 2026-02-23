#include<iostream>
#include<cstring>
#include<vector>
#define MAX 101
#define DOT 0
#define STAR 1
using namespace std;

struct pos{
    int x, y, s;
};

int matrix[MAX][MAX];
int v[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int N, M;
vector<pos> ans;

void input(){
    cin >> N >> M;
    string row;
    for(int i=0; i<N; i++){
        cin >> row;
        for(int j=0; j<M; j++){
            if(row[j] == '.') matrix[i][j] = DOT;  // '.'은 0
            else if(row[j] == '*') matrix[i][j] = STAR;  // '*'은 1
        }
    }
}

// 상하좌우 *인지 탐색
bool isValid(int r, int c, int size){
    for(int i=0; i<4; i++){
        int nr = r + dr[i] * size, nc = c + dc[i] * size;
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) return false;
        if(matrix[nr][nc] == DOT) return false;
    }
    return true;
}

void draw(int r, int c, int size){
    v[r][c] = STAR;
    int n = 1;
    while(n <= size){
        for(int i=0; i<4; i++){
            int nr = r + dr[i] * n, nc = c + dc[i] * n;
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            v[nr][nc] = STAR;
        }
        n++;
    }
}

int solve(){
    int n = 1;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix[i][j] == STAR){
                n = 1;
                while(isValid(i, j, n)) n++;
                if(n != 1) ans.push_back({i, j, n-1});
            }
        }
    }
    
    for(auto n : ans){
        draw(n.x, n.y, n.s);
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix[i][j] != v[i][j]) return -1;
        }
    }
    
    return 1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    int r = solve();
    if(r == 1){
        cout << ans.size() << "\n";
        for(auto n : ans){
            cout << n.x + 1 << " " << n.y + 1 << " " << n.s << "\n";
        }
    }
    else cout << -1;
}