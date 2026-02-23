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
    
    for(auto n : arr){
        sum++;  // B에 대한 +1 증가
        if(n <= B) continue;
        sum += ((n - B) + (C - 1))/C;
    }
    cout << sum << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
}
