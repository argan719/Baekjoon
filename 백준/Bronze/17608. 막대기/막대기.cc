#include<iostream>
#define MAX 100005
using namespace std;

int N;
int arr[MAX];
int max_height;

int main(void){
    int cnt = 0;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];  // i번 막대기의 높이 arr[i]
    }
    max_height = arr[N];
    cnt++;
    for(int i=N-1; i>=1; i--){
        if(max_height < arr[i]) {
            cnt++;
            max_height = arr[i];
        } 
    }
    cout << cnt;
}