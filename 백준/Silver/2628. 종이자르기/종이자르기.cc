#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 101
using namespace std;

int matrix[MAX][MAX];
int N, M;
int num;

vector<int> row = { 0 };  // 잘라야 하는 가로 점선들
vector<int> col = { 0 };  // 잘라야 하는 세로 점선들

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
    
    int max_row = 0, max_col = 0;
    for(int i=1; i<row.size(); i++) max_row = max(max_row, row[i] - row[i-1]);
    for(int i=1; i<col.size(); i++) max_col = max(max_col, col[i] - col[i-1]);
    
    cout << max_row * max_col;
}

int main(){
    input();
    solve();
}