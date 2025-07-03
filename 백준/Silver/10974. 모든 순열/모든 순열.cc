#include<iostream>
#define MAX 10
using namespace std;

int N;
int arr[MAX];
int result[MAX];
int visited[MAX];

void print(){
    for(int i=1; i<=N; i++){
        cout << result[i] << " ";
    }
    cout << "\n";
}

// n: 선택된 숫자 개수
void dfs(int n, int cur){
    result[n] = cur;
    if(n == N){
        print();
    }
    
    for(int i=1; i<=N; i++){
        if(!visited[i]) {
            visited[i] = 1;
            dfs(n+1, i);
            visited[i] = 0;
        }
    }
    
}

int main(void){
    cin >> N;
    for(int i=1; i<=N; i++){
        arr[i] = i;
    }
    dfs(0, 1);
}