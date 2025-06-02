#include <iostream>
#include <climits>
#define MAX 101
using namespace std;

int arr[MAX];

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    int x;
    char alpha;

    int g_cnt = 0;
    int h_cnt = 0;
    int min_x = INT_MAX;
    int max_x = INT_MIN;
    int max_size = INT_MIN;

    for(int i=0;i<N;i++){
        cin >> x >> alpha;
        if(x > max_x) max_x = x;
        if(x < min_x) min_x = x;

        if(alpha == 'G') {
            arr[x] = -1;  // G는 음수
            g_cnt++;
        } 
        else {
            arr[x] = 1;  // H는 양수
            h_cnt++;
        } 
    }

    if(N <= 1) {
        cout << 0;
        exit(0);
    }
    if((g_cnt == h_cnt) || h_cnt == 0 || g_cnt == 0 ) {
        cout << max_x - min_x;
        exit(0);
    }

    int size = max_x - min_x;
    int gcnt = 0;
    int hcnt = 0;

    int i,j,k;

    for(i=min_x; i < max_x; i++){
        for(j=i+1; j <= max_x; j++){
            gcnt = 0;
            hcnt = 0;
            for(k=i; k<=j; k++){
                if(arr[k] == -1) gcnt++;
                else hcnt++;
            }
            if(hcnt == 0 || gcnt == 0 || gcnt == hcnt) {
                size = j-i;
                if(max_size < size) max_size = size;
            }
        }
    }

    cout << max_size;

    // 여기서부터 사이즈 줄여나가면서 뺀게 g면 g_Cnt--
    // 뺀게 h면 (제외된게) h_cnt-- 이런식으로 해야 하지 않나 싶음.
    
    // int size_left = size;
    // int size_right = size;

    // int min_x_tmp = min_x;
    // int max_x_tmp = max_x;

    // while(size_left > 0){
    //     while(arr[++min_x_tmp] == 0){ }
    //     size_left = max_x - min_x_tmp;

    //     if(arr[min_x] == -1) g_cnt_tmp--;
    //     else h_cnt_tmp--;

    //     if(g_cnt == h_cnt) break;
    //     if(h_cnt == 0) break;
    //     if(g_cnt == 0) break;
    // }

    // while(size > 0) {

    //     if(arr[min_x] == -1) g_cnt++;
    //     else h_cnt++;

    //     while(arr[--max_x_tmp] == 0) { }
    //     size_right = max_x_tmp - min_x;

    //     if(arr[min_x] == -1) g_cnt--;
    //     else h_cnt--;
        
    // }

    return 0;
}