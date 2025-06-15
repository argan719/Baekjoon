#include <iostream>
#define MAX 1000002
using namespace std;

int arr_A[MAX];
int arr_B[MAX];

typedef struct V{
    int u;
    int t;
}val;

val a[1002];
val b[1002];

int main() {
    // Please write your code here.
    int N, M;
    cin >> N >> M;


    int tot_t_a = 1;
    int tot_t_b = 1;

    for(int i=1; i<=N;i++){
        cin >> a[i].u >> a[i].t;

        for(int k=0; k<a[i].t; k++){
            arr_A[tot_t_a + k] = arr_A[tot_t_a + k -1] + a[i].u;
        }
        tot_t_a += a[i].t;
    }
    for(int i=1;i<=M;i++){
        cin >> b[i].u >> b[i].t;

        for(int k=0; k<b[i].t; k++){
            arr_B[tot_t_b + k] = arr_B[tot_t_b + k -1] + b[i].u;
        }
        tot_t_b += b[i].t;
    }


    int flag = 0;
    int cnt = 0;

    for(int i=1; i<tot_t_a; i++){
        if(arr_A[i] > arr_B[i] && flag != 1) {
            flag = 1;
            cnt++;
        }
        if(arr_A[i] < arr_B[i] && flag != 2) {
            flag = 2;
            cnt++;
        }
        if(arr_A[i] == arr_B[i] && flag != 3){
            flag = 3;
            cnt++;
        }

    }

    cout << cnt;

    
    return 0;
}