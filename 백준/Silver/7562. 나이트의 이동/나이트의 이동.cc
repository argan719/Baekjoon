#include<iostream>
#include<queue>
#include<cstring>
#include<map>
#define MAX 301
using namespace std;

int matrix[MAX][MAX]; 
int N;
int start_r, start_c;
int end_r, end_c;
vector<int> result;

int dr[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dc[] = {-1, 1, 2, 2, 1, -1, -2, -2};

void bfs(){
    queue<pair<int,int>> q;
    q.push(make_pair(start_r, start_c));
    matrix[start_r][start_c] = 1; // 방문 표시 && depth 정보
    int next_r, next_c;
    
    while(!q.empty()){
        auto a = q.front();
        q.pop();
        if(a.first == end_r && a.second == end_c) {
            result.push_back(matrix[a.first][a.second] - 1);
        }
        
        for(int i=0; i<8; i++){
            next_r = a.first + dr[i];
            next_c = a.second + dc[i]; 
            
            if(!matrix[next_r][next_c]){
                if(next_r >= 0 && next_c >= 0 && next_r < N && next_c < N) {
                    q.push(make_pair(next_r, next_c));
                    matrix[next_r][next_c] = matrix[a.first][a.second] + 1;
                }
            }
        }
    }
    
}

int main(void){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        cin >> start_r >> start_c;
        cin >> end_r >> end_c;
        
        bfs();
        // matrix init
        for(int i=0; i<MAX; i++)
            memset(matrix[i], 0, sizeof(int)*MAX);
    }
    
    for(int i=0; i<T; i++){
        cout << result[i] << endl;
    }
    
}