#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;

int N;
//int arr[MAX][2]; // xi, yi
typedef struct p{
    int x;
    int y;
}pos;
pos arr[MAX]; // 구조체 배열로 변경

bool comp(const pos &a, const pos &b){ // const & 붙이는 버릇!
    if(a.x < b.x) return true;  // 복사 안함, 변경도 안함 (그냥 a 보다 훨씬 효율적)
    if(a.x == b.x) {
        if(a.y <= b.y) return true;
        else return false;
    }
    return false;
}

int main(void){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i].x >> arr[i].y;
    }
    
    sort(arr, arr+N, comp);
    
    for(int i=0; i<N; i++){
        cout << arr[i].x << " " << arr[i].y << "\n";
    }
}
