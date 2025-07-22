#include<iostream>
#include<cstring>
using namespace std;

int main(void){
    string str;
    cin >> str;
    string tmp;
    int flag = 0;
    int cnt = 0;
    
    string arr[] = {"c=", "c-", "z=", "d-", "lj", "nj", "s=", "dz="};
    
    while(str.size() > 0){
       flag = 0;
       for(int i=0; i<=6; i++){
           tmp = str.substr(0,2);
           if(tmp == arr[i]){
               str = str.substr(2);
               flag = 1;
               cnt++;
               break;
           }
        }
        tmp = str.substr(0,3);
        if(tmp == arr[7]) {
            str = str.substr(3);
            flag = 1;
            cnt++;
        }
        if(flag == 0){
            cnt++;
            str = str.substr(1);
        }
    }
    
    cout << cnt;

}