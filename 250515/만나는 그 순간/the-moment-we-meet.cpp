#include <iostream>
#include <algorithm>
#define MAX 2000001
using namespace std;

int A[MAX];
int B[MAX];

typedef struct s{
    char dir;
    int t;
}Move;

// move move_A[MAX];
// move move_B[MAX];

int main() {
    // Please write your code here.
    int N;
    int M;
    cin >> N >> M;

    Move input;

    int pos = 0;
    int tot_time = 0;
    for(int i=0;i<N;i++){
        cin >> input.dir >> input.t;
        
        for(int k=tot_time+1; k <= tot_time + input.t; k++){
            if(input.dir == 'L'){  // 왼쪽 => 음수 (1 감소)
                A[k] = --pos;
            }
            else {  // 오른쪽 => 양수 (1 증가)
                A[k] = ++pos;
            }
        }
        tot_time += input.t;
    }
    int A_tot_time = tot_time;

    pos = 0;
    tot_time = 0;
    for(int i=0;i<M;i++){
        cin >> input.dir >> input.t;

        for(int k=tot_time+1; k <= tot_time + input.t; k++){
            if(input.dir == 'L'){  // 왼쪽 => 음수 (1 감소)
                B[k] = --pos;
            }
            else {  // 오른쪽 => 양수 (1 증가)
                B[k] = ++pos;
            }
        }
        tot_time += input.t;
    }
    int B_tot_time = tot_time;

    int cnt = max(A_tot_time, B_tot_time);

    int i;
    for(i=1; i<=cnt; i++){
        if(A[i] == B[i]) {
            cout << i;
            break;
        }
    }
    if(i > cnt) cout << -1;


    return 0;
}