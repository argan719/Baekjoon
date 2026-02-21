#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int N;
vector<int> arr;
int B, C;


void input(){
    cin >> N;
    int n;
    for(int i=0; i<N; i++){
        cin >> n;
        arr.push_back(n);
    }
    cin >> B >> C;
}

void solve(){
    ll sum = 0;
    ll cnt = 0;
    
    for(auto n : arr){
        cnt = 0;
        
        n -= B; cnt++;
        // 여기서 n이 0뿐만 아니라 음수가 된 경우 고려 필요.
        if(n > 0) {  // n이 1이상인 경우에만 추가 작업 필요.
            cnt += n / C;
            if(n % C !=0) cnt++;
        }
        
        sum += cnt;
    }
    cout << sum << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
}
