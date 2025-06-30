// BFS로 set 써서 다시 풀기
// long 써야 함 주의
#include<iostream>
#include<queue>
#include<set>
using namespace std;

typedef long long ll;
ll A, B;

int bfs(){
    int cnt = 1;
    queue<ll> q;
    set<ll> s;
    q.push(A);
    s.insert(A);  // 방문 표시
    
    while(!q.empty()){
        int len = q.size();
        
        for(int k=0; k<len; k++){ // 매번 이 만큼만 돌아야 연산 수행 개수가 됨. (본인 한 단계 밑에만 (한번에)전부 pop하는 것) - 그게 전부 끝나야 step 증가
            auto cur = q.front();
            q.pop();
            
            if(cur == B) {
                return cnt;
            }
            
            for(auto val : {cur*2, cur*10 + 1}) {
                if(val > B || s.find(val) != s.end()) continue;
                            
                q.push(val);
                s.insert(val);
            }
        }
        
        cnt++;
    }
    return -1;
}


int main(void){
    cin >> A >> B;
    if(A > B) { cout << -1; exit(0); }
    cout << bfs();
}
