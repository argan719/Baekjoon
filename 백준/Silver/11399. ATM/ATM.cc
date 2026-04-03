#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
vector<int> arr;
int ans;

void input(){
    cin >> N;
    int p;
    for(int i=0; i<N; i++){
        cin >> p;
        arr.push_back(p);
    }
    sort(arr.begin(), arr.end()); // 오름차순 정렬
}

void solve(){
    int sum = 0;
    for (auto n : arr){
        sum = sum + n;
        ans += sum;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}
