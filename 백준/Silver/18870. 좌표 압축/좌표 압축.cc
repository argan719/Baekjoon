// 자기보다 작은 게 몇개인지 카운트하면 됨.
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> vec1;
    vector<int> vec2;
    map<int, int> result;
    
    int x;
    for(int i=0;i<N;i++){
        cin >> x;
        vec1.push_back(x);
        vec2.push_back(x);
    }
    sort(vec2.begin(), vec2.end());  // 오름차순 정렬
    
    int idx = 0;
    for(int i=0;i<vec2.size();i++){
        auto it = result.find(vec2[i]);
        if(it == result.end()){
            result.insert(make_pair(vec2[i], idx++));
        }  // 정렬된 값들을 <값, 인덱스>로 insert 
    }

    for(int i=0;i<vec1.size();i++){
        auto it = result.find(vec1[i]);
        cout << it->second << " ";
    }
}