#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int arr_A[MAX];
int arr_B[MAX];

int main() {
    // Please write your code here.
    int N, M;
    cin >> N >> M;

    int t;
    char d;
    int cnt = 0;

    int tot_time = 0;
    int pos = 0;
    for(int i=0; i<N;i++){
        cin >> t >> d;   // t초만큼 방향 d로 이동. 

        for(int k=tot_time + 1; k<= tot_time + t; k++){
            if(d == 'L'){  // 왼쪽 --
                arr_A[k] = --pos;
            }
            else {  // 오른쪽 ++
                arr_A[k] = ++pos;
            }
        }
        tot_time += t;
    }
    int A_tot_time = tot_time;
    int A_last_pos = pos;

    tot_time = 0;
    pos = 0;
    for(int i=0; i<M;i++){
        cin >> t >> d;   // t초만큼 방향 d로 이동. 

         for(int k=tot_time + 1; k<= tot_time + t; k++){
            if(d == 'L'){  // 왼쪽 --
                arr_B[k] = --pos;
            }
            else {  // 오른쪽 ++
                arr_B[k] = ++pos;
            }
        }
        tot_time += t;
    }
    int B_tot_time = tot_time;
    int B_last_pos = pos;

    if(A_tot_time > B_tot_time){
        for(int i=B_tot_time + 1; i<=A_tot_time; i++){
            arr_B[i] = B_last_pos;
        }
    }
    else if(A_tot_time < B_tot_time){
        for(int i=A_tot_time + 1; i<=B_tot_time; i++){
            arr_A[i] = A_last_pos;
        }
    }

    int max_tot_time = max(A_tot_time, B_tot_time);
    //int min_tot_time = min(A_tot_time, B_tot_time);


    for(int i=1; i<=max_tot_time; i++){
        if(arr_A[i] == arr_B[i]){
            if(arr_A[i-1] == arr_B[i-1]) continue;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}