#include <iostream>
#include <algorithm>
#define MAX 2000001
using namespace std;

int matrix[2][MAX];  // A, B


int main() {
    // Please write your code here.
    int N, M;
    cin >> N >> M;

    int u;
    int t;
    int cnt = 0;
    int tot_time = 0;

    for(int i=0;i<N;i++){
        cin >> u >> t;

        for(int k=tot_time + 1; k<= tot_time + t; k++){
            matrix[0][k] = matrix[0][k-1] + u;
        }
        tot_time += t;
    }
    int A_tot_time = tot_time;

    tot_time = 0;
    for(int i=0;i<M;i++){
        cin >> u >> t;

        for(int k=tot_time + 1; k<= tot_time + t; k++){
            matrix[1][k] = matrix[1][k-1] + u;
        }
        tot_time += t;
        
    }
    int B_tot_time = tot_time;

    int tot = max(A_tot_time, B_tot_time);
    int flag = -1;

    for(int i=1; i<=tot; i++){
        if(matrix[0][i] < matrix[1][i] && (flag == 1 || cnt == 0)) {  // A < B
            flag = 0;
            cnt++;
        }
        else if(matrix[0][i] > matrix[1][i] && (flag == 0 || cnt == 0)) {  // A > B
            flag = 1;
            cnt++;
        }
    }

    // 선두가 몇번이 "바뀌는지"
    cout << cnt - 1;

    return 0;
}