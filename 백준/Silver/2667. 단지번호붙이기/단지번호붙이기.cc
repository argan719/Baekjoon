#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX 30
using namespace std;

int matrix[MAX][MAX];
int N;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};


int bfs(int r, int c){
    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    matrix[r][c] = 0;
    int nr, nc;
    int cnt = 1;
    
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            
            if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if(matrix[nr][nc]!=1) continue;
            
            matrix[nr][nc] = 0;
            q.push(make_pair(nr,nc));
            cnt++;
        }
    }
    return cnt;
}


int main(void){
    cin >> N;
    string str;
    vector<int> result;
    
    for(int i=0; i<N; i++){
        cin >> str;
        for(int j=0; j<N; j++){
            matrix[i][j] = str[j] - '0';
        }
    }
    
    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            if(matrix[i][j] == 1) {
                result.push_back(bfs(i, j));
            }
        }
    }
    cout << result.size() << endl;
    sort(result.begin(), result.end());
    for(auto n : result){
        cout << n << endl;
    }
    
}
