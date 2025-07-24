#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 51
using namespace std;

typedef struct pos{
    int x;
    int y;
    int g = 1;
}pos;

int N;
pos arr[MAX];
// 내림차순 정렬
bool comp(const pos &a, const pos &b){
    if(a.x == b.x) return a.y > b.y;
    return a.x > b.x;
}
int main(void){
    // 우선 한 번 정렬 후 내 앞에 사람들과 나 비교 -> 순서대로 출력해야 하므로 정렬X
    int cnt = 0;
  
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i].x >> arr[i].y;
    }
    
    // 나보다 덩치가 큰 사람이 생기면 g++
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i].x < arr[j].x && arr[i].y < arr[j].y) arr[i].g++;
        }
    }
    
    for(int i=0; i<N; i++){
        cout << arr[i].g << " ";
    }
}
