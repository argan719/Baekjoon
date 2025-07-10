#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define MAX 101
using namespace std;

int N, M, K;
int matrix[MAX][MAX];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
//int arr[MAX]
queue<pair<int, int>> q;
vector<int> result;

int bfs(int r, int c){
    q.push(make_pair(r,c));
    matrix[r][c] = 1; // 방문처리
    int nr, nc;
    int cnt = 1;
    
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            
            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;//범위내
            if(matrix[nr][nc]!=0) continue; // 미방문, 조건
            
            matrix[nr][nc] = 1;
            q.push(make_pair(nr,nc));
            cnt++;
        }
    }
    return cnt;
}

int main(void){
    cin >> M >> N >> K;
    int cnt = 0;
    int r;
    
    int x1, y1, x2, y2;
    for(int i=0; i<K; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int i=x1; i<x2; i++){
            for(int j=y1; j<y2; j++){
                matrix[i][j] = 1;
            }
        }
    }
    
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrix[i][j] == 0) {
                r = bfs(i, j);
                result.push_back(r);
            }
        }
    }
    
    cout << result.size() << endl;
    sort(result.begin(), result.end());
    for(auto it = result.begin(); it!=result.end(); it++){
        cout << *it << " ";
    }
}