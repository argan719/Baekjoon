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
        sum++;
        if(n <= B) continue;
        
        n -= B;
        sum += n / C;
        if(n % C !=0) sum++;
    }
    cout << sum << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
}
