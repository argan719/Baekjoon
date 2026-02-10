#include<iostream>
#include<vector>
#include<cstring>
#define MAX 101
using namespace std;

int N, M;
string matrix[MAX];
int matrix2[MAX][MAX];
int cnt;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int k;

typedef struct cross{
    int x;
    int y;
    int s;
}cross;

vector<cross> v; // x, y, 값은 십자가의 크기

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> matrix[i];  // 0 ~ N-1 => 1 ~ N 변경필요 주의.
        for(int j=0; j<M; j++){
            if(matrix[i][j] == '*') cnt++;  // 없애야 하는 *의 수
        }
    }
}

void check(int r, int c){
    int nr, nc;
    int adj = 0;
    int val = 1;
    
            
    for(int i=0; i<4; i++){
        nr = r + (val * dr[i]);
        nc = c + (val * dc[i]);
        
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) break;
        if(matrix[nr][nc] != '*') break;
            
        if(matrix[nr][nc] == '*') adj++;
        
        if(i == 3) {
            val++;
            i = -1;
        }
    }
        
    if(adj >= 4) {
        v.push_back({r, c, adj/4});
        //cnt--;
        //cnt = cnt - (adj/4)*4;
        k++;
    }
}

int solve(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix[i][j] == '*') {
                check(i, j);
            }
        }
    }
    
    int nr, nc;
    for(auto n : v){
        matrix2[n.x][n.y] = 1;  // '*'
        for(int size=1; size<=n.s; size++){
            for(int i=0; i<4; i++){
                nr = n.x + dr[i] * size;
                nc = n.y + dc[i] * size;
                
                matrix2[nr][nc] = 1;  // '*'
            }
            
            
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix[i][j] == '*' && matrix2[i][j] == 0) return -1;
        }
    }
    return 1;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    input();
    if(cnt == 0) { cout << 0 << endl; return 0; }  // k의 범위가 0부터 가능하므로... -1 이 아니라 k를 0으로 출력해야하는 것.
    int r = solve();
    if(r == -1) cout << r;
    else {
        cout << k << endl;
        for(auto n : v){
            cout << n.x + 1 << " " << n.y + 1 << " " << n.s << endl;
        }
    }
}
