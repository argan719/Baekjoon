#include<iostream>
#include<queue>
#include<cstring> // memset
#include<vector>
#define MAX 1001
using namespace std;

int N, M, V;
int matrix[MAX][MAX];
int visited[MAX];
vector<int> dfs_result;
vector<int> bfs_result;

void dfs(int v){
    visited[v] = 1;  // 방문 표시
    dfs_result.push_back(v); // 방문 결과 삽입
    
    for(int i=1; i<=N; i++){  // 인접하고, 미방문이면 dfs 호출
        if(matrix[v][i] && !visited[i]) dfs(i);
    }
}

void bfs(){
    queue<int> q;
    q.push(V); // 시작 정점 삽입
    visited[V] = 1;
    
    while(!q.empty()){
        // 맨 앞 요소 리턴
        auto front = q.front();
        // 삭제 (pop은 반환값 없음)
        q.pop();
        // 방문 결과 삽입
        bfs_result.push_back(front);
        
        for(int i=1; i<=N; i++){
            if(matrix[front][i] && !visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main(void){
    cin >> N >> M >> V;
    
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        // 양방향 인접행렬 생성
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    
    dfs(V);
    // visited 배열 초기화
    memset(visited, 0, sizeof(int)*MAX);
    bfs();
    
    // dfs 결과 출력
    for(auto it = dfs_result.begin(); it != dfs_result.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    // bfs 결과 출력
    for(auto it = bfs_result.begin(); it != bfs_result.end(); it++){
        cout << *it << " ";
    }
    
}