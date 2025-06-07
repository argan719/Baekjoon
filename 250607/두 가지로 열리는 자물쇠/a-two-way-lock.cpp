#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int arr[MAX];
int first[50];

int main() {
    // Please write your code here.
    
    // int second[3];

    int N;
    cin >> N;
    int cnt = 0;

    for(int i=1;i<=3; i++){
        cin >> first[i];
    }
    for(int i=4;i<=6; i++){
        cin >> first[i];
    }


    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=1; k<=N;k++){
                if(  (abs(i-first[1]) <= 2 || abs(i-first[1]) >= N-2 ) && (abs(j-first[2]) <= 2 || abs(j-first[2]) >= N-2) 
                &&  (abs(k-first[3]) <= 2 || abs(k-first[3]) >= N-2)  ) cnt++;

                else if (
                    (abs(i-first[4]) <= 2 || abs(i-first[4]) >= N-2 ) && (abs(j-first[5]) <= 2 || abs(j-first[5]) >= N-2) 
                &&  (abs(k-first[6]) <= 2 || abs(k-first[6]) >= N-2) 
                ) cnt++;
            }
        }
    }

   





    
    // for(int i=1; i<=3; i++){
    //     for(int j=first[i]-2)
    // }




    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=N; j++){
    //         for(int k=1; k<=N; k++){
    //             // if( !((i-2 + N)%N >= first[1]) && !((i+2)%N >= first[1]) ) break;
    //             // if( !((j-2 + N)%N >= first[1]) && !((j+2)%N >= first[1]) ) break;
    //             // if( !((k-2 + N)%N >= first[1]) && !((i+2)%N >= first[1]) ) break;

    //             if(((i-2 + N)%N) <= first[1] || (i+2)%N >= first[1]) {
    //                 if(((j-2 + N)%N) <= first[2] || (j+2)%N >= first[2]) {
    //                     if(((k-2 + N)%N) <= first[3] || (k+2)%N >= first[3]) {
    //                         cnt++; break;
    //                     }
    //                 }
    //             }

    //             if(((i-2 + N)%N) <= first[4] || (i+2)%N >= first[4]) {
    //                 if(((j-2 + N)%N) <= first[5] || (j+2)%N >= first[5]) {
    //                     if(((k-2 + N)%N) <= first[6] || (k+2)%N >= first[6]) {
    //                         cnt++; break;
    //                     }
    //                 }
    //             }

                
    //         }
    //     }
    // }

    cout << cnt;


    return 0;
}