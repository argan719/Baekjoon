#include<iostream>
#include<cstring>
#include<vector>
#include<climits>
using namespace std;

int T;
string control;
// 상좌하우
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int solve(){
    int min_x = 0;
    int min_y = 0;
    
    int max_x = 0;
    int max_y = 0;
    
    int x = 0, y = 0;
    //int nx = 0, ny = 0;
    int flag = 0;
    
    for(auto n : control){
        if(n == 'F'){
            x = x + dx[flag];
            y = y + dy[flag];
        }
        else if(n == 'B'){
            x = x - dx[flag];
            y = y - dy[flag];
        }
        else if(n == 'L'){
            flag = (flag+1) % 4;
        }
        else if(n == 'R'){
            flag = (flag+3) % 4;
        }
        
        if(x < min_x) min_x = x;
        else if(x > max_x) max_x = x;
        
        if(y < min_y) min_y = y;
        else if(y > max_y) max_y = y;
    }
    
    return (max_x - min_x) * (max_y - min_y);
    
}

int main(){
    cin >> T;
    vector<int> result;
    for(int t=0; t<T; t++){
        cin >> control;
        
        result.push_back(solve());
    }
    for(auto n : result){
        cout << n << endl;
    }
}