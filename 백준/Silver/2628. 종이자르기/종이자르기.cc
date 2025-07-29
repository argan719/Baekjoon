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
    
    /*
    int dimension = w * h; // 전체면적
    int max_rectangle = 0;
    int w_line_top = 0; // 가로선
    int w_line_bottom = h;
    int h_line_top = 0; // 세로선 left
    int h_line_bottom =  w; // 세로선 right
     */
    // 그냥 top, bottom, left, right으로 할 걸..
    
    int id, no;
    int max_w = -1;
    int max_h = -1;
    // no를 입력받아 자른다는 것은 -> no : tot-no
    // 전부 잘라놓고 맨 마지막에 넓이 계산 ? -> (처음에 생각한)이게 맞는듯.
    // 자르는 것은 모든 분할 사각형에 해당됨. 즉, 계속 max인 면적만 확인하면 됨. -> no 반례 존재. 그래서 틀림.
    
    vector<int> w_id;
    vector<int> h_id;
    for(int n=1; n<=N; n++){
        cin >> id >> no;
        if(id ==0){//가로
            h_id.push_back(no);
        }else{//세로
            w_id.push_back(no);
        }
    }
    
    sort(w_id.begin(), w_id.end());
    sort(h_id.begin(), h_id.end());
    int tmp;
    int prev = 0;
    for(auto cur : w_id){
        tmp = cur - prev;
        prev = cur;
        if(max_w < tmp) max_w= tmp;
    }
    if(max_w < w - prev) max_w = w-prev;
    
    prev = 0;
    for(auto cur : h_id){
        tmp = cur - prev;
        prev = cur;
        if(max_h < tmp) max_h= tmp;
    }
    if(max_h < h - prev) max_h = h-prev;
    
    cout << max_h * max_w;
    
}