#include<iostream>
#include<vector>
using namespace std;

int N, M;
int T;
typedef long long ll;

vector<ll> vec;
int main(void){
    cin >> T;
    ll ans_1 = 1;
    ll ans_2 = 1;
    ll ans_3 = 1;
    ll ans = 0;
    int div = 1;
    
    for(int t=0; t<T; t++){
        cin >> N >> M;
     // mCn ?? //조합
     // 조합 공식 생각 안나서 찾아봄..
    // nCr = n! / (n-r)!r!
        // mCn = m! / (m-n)! * n!
        ans_1 = 1;
        ans_2 = 1;
        ans_3 = 1;
        // long long으로 해도 따로 게산하니까 오버플로우 발생.
        /*
        for(int i=1; i<=M; i++){
            ans_1 *= i;  // m!
        }
        for(int i=1; i<=M-N; i++){
            ans_2 *= i; // m-n!
        }
        for(int i=1; i<=N; i++){
            ans_3 *= i;  // n!
        }
        ans = ans_1 / (ans_2 * ans_3);
        vec.push_back(ans);
        */
        
        // 분모 약분해서 없애기
        // m * (m-1) * (m-2) * ... 1  / (m-n) * (m-n-1) * (m-n-2) * ... 1
        // m * (m−1) * ... * (m−n+1) / n!
        
        ans = 1;
        div = 1;
        for(int i=M; i >= M-N+1; i--){
            ans *= i;
            ans /= div++;
        }
        vec.push_back(ans);
        
    }
    
    for(auto cur: vec){
        cout << cur << endl;
    }
}
