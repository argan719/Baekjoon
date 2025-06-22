#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

int arr[10];

int main(void){
    
    int min = INT_MAX;
    int result = -1;
    int sum = 0;
    
    for(int i=0; i<10; i++){
        cin >> arr[i];
    }
    

    for(int j=0; j<10; j++){
        sum += arr[j];
          if(abs(100-sum) <= min){
              min = abs(100-sum);
              if(sum >= result)result = sum;
          }
    }
    
    cout << result;
}