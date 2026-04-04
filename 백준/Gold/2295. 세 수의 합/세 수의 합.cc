// x + y + z = k
// x + y = k - z
// x, y, z, k가 서로 같아도 된다.
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define MAX 1001
using namespace std;

int N;
vector<int> arr;
set<int> sum;

bool comp(const int& a, const int& b){
    return a > b;
}

void input(){
    cin >> N;
    int n;
    for(int i=0; i<N; i++){
        cin >> n; arr.push_back(n);
    }
}

void solve(){
    // 10^6 * 2
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            // 중복 허용.
            sum.insert(arr[i] + arr[j]);
        }
    }
    
    sort(arr.begin(), arr.end(), comp);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(sum.find(arr[i] - arr[j]) != sum.end()) {
                cout << arr[i]; return;
            }
        }
    }
    
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}
