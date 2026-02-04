#include<iostream>
#include<cstring>
#include<vector>
#define MAX 12
using namespace std;

int matrix[MAX][MAX];
int R,C;

int dr[] = { -1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

vector<pair<int,int>> down;

void input(){
    string s;
    
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        cin >> s;
        for(int j=0; j<C; j++){
            if(s[j] == '.') matrix[i][j+1] = 0; // 바다
            else if(s[j] == 'X') matrix[i][j+1] = 1; // 땅
        }
    }
}

void solve(){
    int cnt = 0;
    
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(matrix[i][j] == 1){
                
                for(int k=0; k<4; k++){
                    if(matrix[i + dr[k]][j + dc[k]] == 0) cnt++;
                }
                if(cnt >= 3) down.push_back(make_pair(i,j));  //matrix[i][j] = 0;
                cnt = 0;
            }
        }
    }
    
    for(auto cur : down){
        matrix[cur.first][cur.second] = 0;
    }
    
    
    
    int flag = 0;
    cnt = 0;
    int r_low = 1; int r_high = R;
    int c_low = 1; int c_high = C;
    
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(matrix[i][j] == 1) { flag = 1; cnt++; break;}
        }
        if(flag == 1 && cnt == 1) { r_low = i; r_high = i;}
        else if(flag) r_high = i;
        flag = 0;
    }
    
    flag = 0;
    cnt = 0;
    for(int j=1; j<=C; j++){
        for(int i=1; i<=R; i++){
            if(matrix[i][j] == 1) { flag = 1; cnt++; break;}
        }
        if(flag == 1 && cnt == 1) {c_low = j; c_high = j;}
        else if(flag) c_high = j;
        flag = 0;
    }
    
    
    for(int i=r_low; i<=r_high; i++){
        for(int j=c_low; j<=c_high; j++){
            if(matrix[i][j] == 0) cout << '.';
            else if(matrix[i][j] == 1) cout << 'X';
        }
        cout << endl;
    }

}


int main(){
    input();
    
    solve();
}