#include<iostream>
#include <climits>
#include <cstring>
#define MAX 21
using namespace std;

int arr[MAX];
int line[MAX];

int main(void){
    int P;
    cin >> P;
    int T;
    int cnt = 0;
    int cur_pos;
    int min = 0;
   
    for(int test_case = 1; test_case <= P; test_case++){
        cin >> T;
        cnt = 0;
        min = INT_MAX;
        memset(line, 0, sizeof(int)*MAX);  
        memset(arr, 0, sizeof(int)*MAX);
        // 20명 입력받음
        for(int i=1; i<=20; i++){
            cin >> arr[i];
        }
        // 맨처음에 첫번째 학생 위치
        line[1] = arr[1];
        // 그 다음 학생 올 자리(줄의 맨 뒤)
        cur_pos = 2;
 
        for(int i=2;i<=20; i++){
            line[cur_pos] = arr[i];
            
            for(int j=1; j<cur_pos; j++){
                if(arr[i] < line[j]) {
                    if(min > j) min = j;
                }
            }
            if(min != INT_MAX) {
                for(int k=cur_pos-1; min <= k ; k--){
                     line[k+1] = line[k];
                     cnt++;
                 }
               line[min] = arr[i];
            }
            cur_pos++;
            min = INT_MAX;
        }
                
        cout << T << " " << cnt << endl;
    }
    
}