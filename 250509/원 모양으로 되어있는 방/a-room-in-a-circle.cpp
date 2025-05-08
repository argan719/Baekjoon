#include <iostream>
#include<bits/stdc++.h>
#define MAX 1005
using namespace std;

int arr[MAX];

int main() {
    // Please write your code here.
    int N;
    int sum = 0;
    int cnt = 0;
    int dist = 0;
    int pos = 0;
    int MIN_DIST = INT_MAX;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    for(int start = 1; start <= N; start++){
        cnt = sum;
        dist = 0;
        cnt -= arr[start];
        dist += 0;
        pos = start + 1;

        while(1){
            pos = pos % N;
            if(pos == 0) pos += N;
            if(pos == start) break;
            //cout << start << " " << pos << endl;

            dist += cnt;
            cnt -= arr[pos];
            pos++;
        }
        if(MIN_DIST > dist) MIN_DIST = dist;
    }

    cout << MIN_DIST;


    return 0;
}