// 어쨋든 가로 조각 중 가장 긴 가로 * 세로 조각 중 가장 긴 세로가 답이 됨.
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 101
using namespace std;

int matrix[MAX][MAX];
int N, M;
int num;

vector<int> row;  // 잘라야 하는 가로 점선들
vector<int> col;  // 잘라야 하는 세로 점선들

void input(){
    cin >> M >> N;
    cin >> num;
    int type, val;
    for(int i=0; i<num; i++){
        cin >> type >> val;
        if(type == 0) row.push_back(val);
        else col.push_back(val);
    }
}
void solve(){
    row.push_back(N); col.push_back(M);
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    
    int s = 0;
    int max_row = 1;
    int max_col = 1;
    for(auto n : row){
        max_row = max(max_row, n - s);
        s = n;
    }
    s = 0;  // 초기화!!!!
    for(auto n : col){
        max_col = max(max_col, n - s);
        s = n;
    }
    cout << max_row * max_col;
}

int main(){
    input();
    solve();
}
