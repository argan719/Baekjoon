#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include <cctype>
#include<string>
using namespace std;

int main(void){
    int N, M;
    string name;
    map<string, string> pkmn_num;
    map<string, string> pkmn_name;
    vector<string> question;
    
    cin >> N >> M;
    
    for(int i=1;i<=N;i++){  // string, string으로 1~N번까지 입력받기
        cin >> name;
        pkmn_num.insert(make_pair(to_string(i), name));
        pkmn_name.insert(make_pair(name, to_string(i)));
    }
    for(int i=0;i<M;i++){  // 맞춰야 할 포켓몬 입력받기 (번호, 이름 둘 다 string으로)
        cin >> name; 
        question.push_back(name);
    }
    
    for(int i=0;i<M;i++){
        name = question[i];
        if(isdigit(name[0])){
            // 번호를 입력받은 경우
            cout << pkmn_num[name] << "\n";
        }
        else {
            // 이름을 입력받은 경우
            cout << pkmn_name[name] << "\n";
        }
    }
    
}