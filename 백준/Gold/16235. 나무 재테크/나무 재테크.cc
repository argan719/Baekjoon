#include<iostream>
#include<vector>
#include<deque>
#include<cstring>
#include<algorithm>
#define MAX 11
using namespace std;

int N, M, K;
int matrix[MAX][MAX]; // 땅의 양분
int A[MAX][MAX]; // 양분 추가

struct Tree{
    int r;
    int c;
    int age;
};

//vector<vector<int>> tree(MAX, vector<int>(MAX,0));
deque<int> tree[MAX][MAX];
vector<Tree> die;
vector<pair<int,int>> new_tree;

// 인접 8칸
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int ans;


void input(){
    Tree tmp;
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> A[i][j];
            matrix[i][j] = 5;  // 초기 양분 5
        }
    }
    for(int i=0; i<M; i++){
        cin >> tmp.r >> tmp.c >> tmp.age;
        tree[tmp.r][tmp.c].push_back(tmp.age);
    }
}

void solve(){
    
    for(int k=1; k<=K; k++){
        //vector<Tree> die;
        int sum = 0;

        // 좌표가 같은 경우 나이 오름차순 정렬
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(tree[i][j].size() == 0) continue;
                
                sort(tree[i][j].begin(), tree[i][j].end());
                int n = tree[i][j].size();
                
                sum = 0;
                for(int k=0; k<n; k++){
                    int cur = tree[i][j].front();
                    
                    if(matrix[i][j] < cur) {
                        sum += cur/2;
                    }
                    else{
                        matrix[i][j] -= cur;
                        tree[i][j].push_back(cur + 1);
                        if((cur +1) % 5 == 0) new_tree.push_back({i, j});
                    }
                    tree[i][j].pop_front();
                }
                matrix[i][j] += sum;
            }
        }
        
       
        // 가을
        for(auto cur : new_tree){
            // 인접 8칸에 대해 번식 수행 & 범위내
            for(int dir=0; dir<8; dir++){
                int nr = cur.first + dr[dir]; int nc = cur.second + dc[dir];
                if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
                
                tree[nr][nc].push_back(1);
            }
        }
        new_tree.clear();
        
        
        // 겨울
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                matrix[i][j] += A[i][j];
            }
        }
    }
    
    // 정답 출력
    //cout << tree.size() << "\n";
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(tree[i][j].size() == 0) continue;
            ans += tree[i][j].size();
        }
    }
    cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}

