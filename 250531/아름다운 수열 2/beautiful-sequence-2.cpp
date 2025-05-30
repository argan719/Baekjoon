#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;

int arr_A[MAX];
int arr_B[MAX];

int arr_cnt[MAX];
int arr_copy[MAX];

int main() {
    // Please write your code here.

    int N, M;
    int cnt = 0;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> arr_A[i];
    }
    for(int i=0;i<M; i++){
        cin >> arr_B[i];
        arr_cnt[arr_B[i]]++;
    }

    if(N < M) {
        cout << 0;
        exit(1);
    }

    int i,j;
    for(i=0; i<=N-M; i++){
        memcpy(arr_copy, arr_cnt, sizeof(arr_copy));
        for(j=i; j< i+M; j++){
            if(arr_copy[arr_A[j]] > 0) arr_copy[arr_A[j]]--;
            else break;
        }
        if(j >= i+M) cnt++;
    }

    cout << cnt;


    return 0;
}