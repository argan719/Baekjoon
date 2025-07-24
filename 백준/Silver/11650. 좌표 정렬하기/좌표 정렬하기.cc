// 벡터 pair 로 다시 풀기

#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100001
using namespace std;

int N;
//vector<pair<int,int>> vec(MAX);
vector<pair<int,int>> vec;

int main(void){
    cin >> N;
    int first, second;
    for(int i=0; i<N; i++){
        cin >> first >> second;
        vec.push_back(make_pair(first, second));
    }
    sort(vec.begin(), vec.end());
    
    for(auto cur: vec){
        cout << cur.first << " " << cur.second << "\n";
    }
}