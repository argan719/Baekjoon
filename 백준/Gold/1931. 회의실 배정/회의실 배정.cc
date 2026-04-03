#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int N;
int cnt;
vector<pair<ll, ll>> arr;

bool comp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

void input(){
    int s, e;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> s >> e;
        arr.push_back({s,e});
    }
    sort(arr.begin(), arr.end(), comp);  // 정렬
}

void solve(){
    ll end = 0;
    for(auto cur : arr){
        if(end <= cur.first) {
            end = cur.second;
            cnt++;
        }
    }
    cout << cnt;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    solve();
}