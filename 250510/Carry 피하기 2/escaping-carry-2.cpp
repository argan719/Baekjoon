#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#define MAX 21
using namespace std;

int matrix[MAX][4];
int count[MAX];

int main() {
    // Please write your code here.
    // carry 가 발생한다는 걸 어케 판단할 수 있을까
    // 일단 자릿수가 늘어나는걸로는 안됨. 반례) 71 + 19 = 90 carry는
    // 발생했지만 자릿수는 그대로임.

    int max = 0;
    int acc = 0;
    int num;
    int len;
    int mul;
    int sum = 0;
    int num1, num2, num3;
    int carry_cnt = 0;
    string str;
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> num;
        str = to_string(num);
        len = str.length();
        for(int j=3; j>=0; j--){
            if(len > 0) matrix[i][j] = str[--len] - '0';
            else matrix[i][j] = 0;
        }
    }


    int c;
    for(int i=0;i<=N-3;i++){
        for(int j=i+1; j<=N-2;j++){
            for(int k=j+1; k<=N-1; k++){
                acc = 0;
                mul = 1;
                for(c = 3; c>=0; c--){
                    sum = matrix[i][c] + matrix[j][c] + matrix[k][c];
                    if(sum >= 10) {
                        carry_cnt++; break;
                    }
                    else {
                        acc+= mul * sum;
                    }
                    mul *= 10;
                }
                if(c < 0 && max < acc) max = acc;
            }
        }
    }

    if(max == 0) cout << -1;
    else cout << max;


    return 0;
}