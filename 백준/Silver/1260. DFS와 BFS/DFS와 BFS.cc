#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#define MAX 1001

using namespace std;

int N, M, V;
int matrix[MAX][MAX];
int visited[MAX];

vector<int> bfs_result;
vector<int> dfs_result;

void bfs(){
    queue<int> q;   // [1]
    q.push(V);  // [2] 시작정점 삽입
    visited[V] = 1;
    
    
    while(!q.empty()) {  // [3] queue에 데이터 있는 동안
        // 맨 앞 요소 리턴
        auto front = q.front();
        // 삭제 - pop은 리턴값 없음
        q.pop();        // 데이터 한 개 꺼냄
        // 방문 결과 삽입
        bfs_result.push_back(front);
        
        // 정점 번호는 1부터 N까지이다.
        for(int i=1; i<=N; i++){  // 연결된 노드 or 방향 반복처리
            if(matrix[front][i] && !visited[i]) {  // 범위 내 + 미방문 + (조건 맞으면)
                q.push(i);       // 단위작업 (해야할 일)
                visited[i] = 1;
            }
        }
    }
    
    
}

void dfs(int v){
    visited[v] = 1;  // 방문표시
    dfs_result.push_back(v);
    
    // 정점 번호는 1부터 N까지이다.
    for(int i=1; i<=N; i++){
        if(matrix[v][i] && !visited[i]) dfs(i);  // 인접하고 미방문이면 재귀호출
    }
}

int main(void)
{
    cin >> N >> M >> V;
    
    int r, c;
    // 양방향 인접행렬 생성
    for(int i=0; i<M; i++){
        cin >> r >> c;
        matrix[r][c] = 1;
        matrix[c][r] = 1;
    }
    
    dfs(V);
    // visited 배열 초기화
    memset(visited, 0, sizeof(int)*MAX);
    
    bfs();
    
    // DFS 결과 출력
    for(auto cur : dfs_result) {
        cout << cur << " ";
    }
    cout << endl;
    // BFS 결과 출력
    for(auto cur : bfs_result) {
        cout << cur << " ";
    }
}