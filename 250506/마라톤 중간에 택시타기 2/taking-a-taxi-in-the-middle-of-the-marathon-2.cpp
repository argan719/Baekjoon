#include <iostream>
#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int x[MAX];
int y[MAX];

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> x[i] >> y[i];
    }

    int next = 0;
    int sum = 0;
    int min = INT_MAX;

    for(int i=2; i<=N-1; i++){
        for(int k=1; k<N; k++){
            if(k == i) continue;
            next = k + 1;
            if(next == i) next++;
            sum += abs(x[k]-x[next]) + abs(y[k] - y[next]);
        }
        if(min > sum) min = sum;
        sum = 0;
    }

    cout << min;

    return 0;
}