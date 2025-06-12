#include <iostream>
#include <climits>
#define MAX 101
#define MAX_TIME 251
using namespace std;

typedef struct DD{
    int k_handshake;
    int state;
}DD;

typedef struct TT{
    int x;
    int y;
}TT;

DD developer[MAX]; // 1~N번에 해당하는 개발자 정보
int arr_time[MAX_TIME];  // 초별로 검사하며 시뮬레이션 돌리기 위한 배열
TT handshake[MAX_TIME];  // 악수에 대한 정보 저장만 하기 위한 배열


int main() {
    // Please write your code here.
    int N, K, P, T;
    cin >> N >> K >> P >> T;

    developer[P].k_handshake = K;
    developer[P].state = 1;

    int x, y;
    int t;

    int min = 300;  // P가 등장한 최초 시간
    int max = INT_MIN;

    for(int i=0;i<T;i++){
        cin >> t >> x >> y;
        handshake[t].x = x;
        handshake[t].y = y;
        if((x == P || y == P) && t < min) min = t;
        if(t > max) max = t;
    }

    int flag = 0;

    for(int i=min; i<=max; i++){
        if(developer[handshake[i].x].k_handshake > 0) {
            developer[handshake[i].x].k_handshake--;

            if(developer[handshake[i].y].state == 0) {
                flag = 1;
                developer[handshake[i].y].k_handshake = K;
                developer[handshake[i].y].state = 1;
            }

        }
        if(developer[handshake[i].y].k_handshake > 0 && !flag){
            developer[handshake[i].y].k_handshake--;
            if(developer[handshake[i].x].state == 0){
                developer[handshake[i].x].k_handshake = K;
                developer[handshake[i].x].state = 1;
            }
        }
        flag = 0;
    }
    
    for(int i=1; i<=N; i++){
        cout << developer[i].state;
    }

    return 0;
}