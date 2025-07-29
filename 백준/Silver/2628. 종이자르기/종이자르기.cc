#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 101
using namespace std;

int matrix[MAX][MAX];
int main(void){
    int w, h;
    int N;
    cin >> w >> h;
    cin >> N;
    
    int id, no;
    int max_w = -1;
    int max_h = -1;
    int tmp;
    int prev = 0;
    
    vector<int> row; // 행번호 = 가로 점선
    vector<int> col; // 열번호 = 세로 점선
    for(int n=1; n<=N; n++){
        cin >> id >> no;
        if(id ==0){//가로로 자르는 점선
            row.push_back(no);
        }else{//세로로 자르는 점선
            col.push_back(no);
        }
    }
    row.push_back(h);
    col.push_back(w);
    
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    
    for(auto cur : row){
        tmp = cur - prev;
        prev = cur;
        if(max_h < tmp) max_h= tmp;
    }
    //if(max_w < w - prev) max_w = w-prev;
    
    prev = 0;
    for(auto cur : col){
        tmp = cur - prev;
        prev = cur;
        if(max_w < tmp) max_w = tmp;
    }
    //if(max_h < h - prev) max_h = h-prev;
    
    cout << max_h * max_w;
    
}