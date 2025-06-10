#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int matrix[100][2];

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    for(int i=0; i<N;i++){
        cin >> matrix[i][0] >> matrix[i][1];  // x y
    }

    int min_x = 40100;
    int min_y = 40100;
    int max_x = 0;
    int max_y = 0;

    int ans = INT_MAX;

    for(int i=0; i<N; i++){
        min_x = 40100;
        min_y = 40100;
        max_x = 0;
        max_y = 0;

        for(int j=0; j<N; j++){
            if(i == j) continue;
            if(min_x > matrix[j][0]) min_x = matrix[j][0];
            if(max_x < matrix[j][0]) max_x = matrix[j][0];

            if(min_y > matrix[j][1]) min_y = matrix[j][1];
            if(max_y < matrix[j][1]) max_y = matrix[j][1];
            
        }
        ans = min(ans, ((max_x - min_x) * (max_y - min_y)));
    }

    cout << ans;


    return 0;
}