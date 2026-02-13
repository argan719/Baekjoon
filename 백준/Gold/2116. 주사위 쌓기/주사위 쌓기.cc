#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX 10001
using namespace std;

int N;  // 주사위의 개수
int dice[MAX][6];// 주사위
vector<int> v[MAX];  // 4면 저장

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<6; j++){
            cin >> dice[i][j];
        }
    }
}

int check(int a){
    if(a == 0) return 5;
    if(a == 1) return 3;
    if(a == 2) return 4;
    if(a == 3) return 1;
    if(a == 4) return 2;
    if(a == 5) return 0;
    
    return -1;
}

void solve(){
    // 0번(1번) 주사위를 기준으로 - 마주보는 면을 A ~ F로 돌아가며 설정.
    int val;
    int c;
    int sum = 0;
    int max_val = 0;
    int result = 0;
    
    for(int i=0; i<6; i++){
        sum = 0;
        max_val = 0;
        
        val = dice[0][i];  // 1번 주사위와 마주볼 면 설정
        c = dice[0][check(i)];
        
        for(int p = 0; p<6; p++){
            if(dice[0][p] == val || dice[0][p] == c) continue;
            if(max_val < dice[0][p]) max_val = dice[0][p];
        }
        sum += max_val;
        max_val = 0;
        
        for(int a=1; a<N; a++){
            for(int b=0; b<6; b++){
                if(dice[a][b] == val) {
                    c = val;
                    val = dice[a][check(b)];
                    break;
                }
            }
            
            for(int p = 0; p<6; p++){
                if(dice[a][p] == val || dice[a][p] == c) continue;
                if(max_val < dice[a][p]) max_val = dice[a][p];
            }
            sum += max_val;
            max_val = 0;
        }
        
        if(sum > result) result = sum;
    }
    cout << result;
    
}


int main(){
    input();
    solve();
    return 0;
}