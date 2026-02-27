#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAX 16
using namespace std;

int L, C;
vector<char> arr;
char ans[MAX];

void input(){
    cin >> L >> C;
    char c;
    for(int i=0; i<C; i++){
        cin >> c;
        arr.push_back(c);
    }
    sort(arr.begin(), arr.end());
}

void dfs(int n, int start){
    if(n == L){
        // 정답처리
        int cnt = 0;
        for(int j=0; j<L; j++){
            char c = ans[j];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
        }
        if(cnt == 0 || L-cnt <= 1) return;
        
        for(int j=0; j<L; j++){
            cout << ans[j];
        }
        cout << "\n";
        return;
    }
    
    // 하부함수
    for(int j=start; j<C; j++){
        ans[n] = arr[j];
        dfs(n+1, j+1);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    input();
    dfs(0, 0);
}
