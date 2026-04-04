#include<algorithm>
#include<iostream>
#include<set>
#include<vector>
using namespace std;

int N;
vector<int> arr;
vector<int> nums;
set<int> s;
vector<int> ans;

void input(){
    cin >> N;
    int num;
    for(int i=1; i<=N; i++) {
        cin >> num;
        arr.push_back(num);
    }
}

void solve(){
    
    set<int> s(arr.begin(), arr.end());
    nums.assign(s.begin(), s.end());
    
    for(auto target : arr){
        auto low = lower_bound(nums.begin(), nums.end(), target);
        cout << low - nums.begin() << " ";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}