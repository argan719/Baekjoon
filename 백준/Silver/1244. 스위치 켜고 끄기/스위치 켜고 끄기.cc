#include<iostream>
#define MAX 101
using namespace std;

int arr[MAX];
typedef struct student{
    int gender; //1 남 2 여
    int val;
}student;
student st[MAX];  // 굳이 학생정보를 저장할 필요가X.
int N;  // 스위치 개수
int M;  // 학생 개수

void solve(int gender, int val){
    int left = val - 1;
    int right = val + 1;
    if(gender == 1){ // 남
        for(int i=1; i<=N; i++){
            if(i%val == 0) arr[i] ^= (1<<0);
        }
    }
    else{ // 여
        arr[val] ^= (1<<0);
        while(left >= 1 && right <= N && arr[left] == arr[right]){
            arr[left] ^= (1<<0);
            arr[right] ^= (1<<0);
            left--; right++;
        }
    }
}

void print(){
    for(int i=1; i<=N; i++){
        cout << arr[i] << " ";
        if(i%20 == 0) cout << endl;
    }
}
int main(void){
    int gender;
    int val;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    cin >> M;
    for(int i=1; i<=M; i++){
        cin >> gender >> val;
        solve(gender, val);
    }
    print();
}