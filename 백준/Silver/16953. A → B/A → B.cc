#include<iostream>
#include<cstring>
#include<set>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;

ll A, B;
set<ll> v;

int bfs(){
    int step = 1;
    int len;
    queue<ll> q;
    q.push(A);
    v.insert(A); // 방문표시
    
    while(!q.empty()){
        len = q.size();
        
        for(int i=0; i<len; i++){
            
            auto cur = q.front();
            q.pop();
            
            // 정답처리는 이곳에서
            if(cur == B) return step;
            if(cur > B) continue;
            
            for(auto n : {cur*2, cur*10+1}){
                // 미방문 조건 맞으면
                if(n > B || v.find(n) != v.end()) continue;
                
                // 단위작업
                q.push(n);
                v.insert(n);
            }
        }
        step++;
    }
    return -1;
}

int main(){
    cin >> A >> B;
    
    cout << bfs();
    return 0;
}