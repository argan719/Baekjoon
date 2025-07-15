#include<iostream>
#include<algorithm>
#define MAX 101
using namespace std;

int arr[MAX];
int main(void){
    int N, M;
    int a,b;
    cin >> N >> M;
    // 초기 입력된 상태
    //처음에는 바구니에 적혀있는 번호와 같은 번호가 적힌 공이 들어있다.
    for(int i=1; i<=N; i++){
        arr[i] = i;
    }
    
    for(int i=0;i<M; i++){
        cin >> a >> b;
        swap(arr[a], arr[b]); //algorithm
    }
    
    for(int i=1; i<=N; i++){
        cout << arr[i] << " ";
    }
    
}