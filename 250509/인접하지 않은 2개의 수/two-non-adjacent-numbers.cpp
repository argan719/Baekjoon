#include <iostream>
#include <climits>
#define MAX 101
using namespace std;


int num[MAX];

int main() {
    // Please write your code here.
    int max = INT_MIN;
    int N;
    int sum = 0;
    cin >> N;
    for(int i=1; i<=N;i++){
        cin >> num[i];
    }

    for(int i=1; i<=N; i++){
        sum = num[i];
        for(int k= i+2; k<=N; k++){
            if(max < sum + num[k]) max = sum + num[k];
        }
    }
    cout << max;

    return 0;
}