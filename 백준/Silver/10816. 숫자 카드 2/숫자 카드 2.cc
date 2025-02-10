#include<iostream>
#include<vector>
#include<set>
#include<map>
#define MAX 20000001
#define OFFSET 10000000
using namespace std;

int arr[MAX];

int main(void){
    int N, M;
    cin >> N;
    set<int> s;
    map<int, int> m;
    vector<int> vec;
    
    int n;
    for(int i=0;i<N;i++){
        cin >> n;
        arr[n+OFFSET] = arr[n+OFFSET] + 1;
    }
    cin >> M;
    for(int i=0;i<M;i++){
        cin >> n;
        vec.push_back(arr[n+OFFSET]);
    }
    
    for(int i=0;i<M;i++){
        cout << vec[i] << " ";
    }
    
}