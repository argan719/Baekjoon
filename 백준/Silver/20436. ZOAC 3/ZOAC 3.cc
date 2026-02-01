#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<cmath>
using namespace std;


char sl, sr;
char matrix[3][10];
string cmd;
set<char> right_char;
int cnt;

int rightx, righty;
int leftx, lefty;

void calc(int x, int y, char cur){
    int dir = 0;
    
    // 오른손이 해야하는 문자
    if(right_char.find(cur) != right_char.end()){
        dir = abs(rightx - x) + abs(righty - y);
        rightx = x;
        righty = y;
    }
    else{ // 왼손이 해야하는 문자
        dir = abs(leftx - x) + abs(lefty - y);
        leftx = x;
        lefty = y;
    }
        
    cnt += dir;
    cnt += 1;
}

void solve(){
    
    for(int i=0; i<3; i++){
        for(int j=0; j<10; j++){
            if(matrix[i][j] == sl) {
                leftx = i;
                lefty = j;
            }
            else if(matrix[i][j] == sr){
                rightx = i;
                righty = j;
            }
        }
    }
    
    
    for(char cur : cmd){
        for(int i=0; i<3; i++){
            for(int j=0; j<10; j++){
                if(matrix[i][j] == cur) calc(i, j, cur);
            }
        }
        
    }
}

int main(){
    cin >> sl >> sr;
    
    matrix[0][0] = 'q';
    matrix[0][1] = 'w';
    matrix[0][2] = 'e';
    matrix[0][3] = 'r';
    matrix[0][4] = 't';
    matrix[0][5] = 'y';
    right_char.insert('y');
    matrix[0][6] = 'u';
    right_char.insert('u');
    matrix[0][7] = 'i';
    right_char.insert('i');
    matrix[0][8] = 'o';
    right_char.insert('o');
    matrix[0][9] = 'p';
    right_char.insert('p');
    
    matrix[1][0] = 'a';
    matrix[1][1] = 's';
    matrix[1][2] = 'd';
    matrix[1][3] = 'f';
    matrix[1][4] = 'g';
    matrix[1][5] = 'h';
    right_char.insert('h');
    matrix[1][6] = 'j';
    right_char.insert('j');
    matrix[1][7] = 'k';
    right_char.insert('k');
    matrix[1][8] = 'l';
    right_char.insert('l');
    matrix[1][9] = ' ';
    
    matrix[2][0] = 'z';
    matrix[2][1] = 'x';
    matrix[2][2] = 'c';
    matrix[2][3] = 'v';
    matrix[2][4] = 'b';
    right_char.insert('b');
    matrix[2][5] = 'n';
    right_char.insert('n');
    matrix[2][6] = 'm';
    right_char.insert('m');
    matrix[2][7] = ' ';
    matrix[2][8] = ' ';
    matrix[2][9] = ' ';
    
    cin >> cmd;
    
    solve();
    
    cout << cnt << endl;
}