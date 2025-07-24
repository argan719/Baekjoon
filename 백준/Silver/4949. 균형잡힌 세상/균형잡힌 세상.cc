#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;

int main(void){
    string str;
    string tmp;
    vector<string> vec;
    //stack<char> st; // 스택 생성
    
    int cnt_small = 0; // 소괄호
    int cnt_large = 0;  // 대괄호
    int start = 0;
    int flag = 0;
    int prev = 0;  // 추가  1이면 소괄호 2이면 대괄호
    
    // 엔터, . 전부 포함하여 계속 입력받기 위함
    // 마지막 온점 하나가 종료조건이 되야 함.
    while(1){
        getline(cin, str);
        if(str == ".") break;
        vec.push_back(str);
        str="";
    }
    
    /*
    for(auto cur : vec){
        cnt_small = 0;
        cnt_large = 0;
        flag = 0;  // 처음부터 설계 잘못됨. 순서까지 고려 필요.  // ( [ ) ]
        prev = 0;
        for(int i=0; i<cur.size(); i++){
            if((prev == 1 && cur[i] == ']') || (prev == 2 && cur[i] == ')')) {flag = 1; break;}

            if(cur[i] == '(') { cnt_small++; prev = 1;}
            else if(cur[i] == ')') cnt_small--;
            else if(cur[i] == '[') { cnt_large++; prev = 2;}
            else if(cur[i] == ']') cnt_large--;
            
            if(cnt_small < 0 || cnt_large < 0) {flag = 1; break;} // 조건 추가 필요.
        }
        if(!flag && cnt_small == 0 && cnt_large == 0) cout << "yes";
        else cout << "no";
        cout << endl;
    }*/
    
   // 스택을 쓰는 건 어떤지 생각해봄.
    for(auto cur : vec) {
        flag = 1;
        stack<char> st;  // 새로 선언.
        
        for(int i=0; i<cur.size(); i++){
            if(cur[i] == '(' || cur[i] == '[') st.push(cur[i]);
            else if(cur[i] == ')') {
                if(st.empty() || st.top() != '(') {flag = 0; break;}
                st.pop();
            }
            else if(cur[i] == ']') {
                if(st.empty() || st.top() != '[') {flag = 0; break;}
                st.pop();
            }
            //if(st.empty()) {flag = 0; break;}
        }
        if(flag && st.empty()) cout << "yes";  // 스택이 비어있으면 짝 맞는 것.
        else cout << "no";
        cout << "\n";
    }
    
    

}