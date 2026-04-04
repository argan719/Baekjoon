#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> arr;

void input(){
    cin >> N;
    int num;
    for(int i=1; i<=N; i++) {
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());  // 정렬 필수
    
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> num;
        cout << (int)(binary_search(arr.begin(), arr.end(), num)) << "\n";
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    //solve();
}