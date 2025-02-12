#include<bits/stdc++.h>
using namespace std;

typedef struct{
    string s;
    int len;
}ST;

bool compare(ST a, ST b){
    if(a.len < b.len) return true;
    else return false;
}

int main(void){
    int N;
    cin >> N;
    string s;
    
    map<string, int> word;
    vector<ST> vec;
    
    for(int i=0;i<N;i++){
        cin >> s;
        word.insert(make_pair(s, s.length()));  // 알파벳순 오름차순 정렬 완료
    }
    ST p;
    auto iter = word.begin();
    for(;iter!=word.end(); iter++){
        p.s = iter->first;
        p.len = iter->second;
        vec.push_back(p);
    }
    
    stable_sort(vec.begin(), vec.end(), compare); // 길이로 오름차순 정렬 완료
    
    for(int i=0;i<vec.size();i++){
        cout << vec[i].s << "\n";
    }
}