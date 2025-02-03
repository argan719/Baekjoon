#include<iostream>
#include<cstring>  
#define MAX 30
using namespace std;

int main(void){
    int info[MAX];
    for(int i=0;i<MAX;i++){
        info[i] = -1;
    }
    
    string s;
    cin >> s;
    int idx;
    char word[101];
    strcpy(word, s.c_str());  // char 배열로 복사
    
    // 소문자는 아스키 97부터 시작하는걸로 알고있음
    for(int i=0;i<s.length();i++){
        idx = int(word[i]);
        if(info[idx-97] == -1){
            info[idx-97] = i;
        }
    }
    
    for(int i=0;i<25;i++){
        cout << info[i] << " ";
    }
    cout << info[25];
}