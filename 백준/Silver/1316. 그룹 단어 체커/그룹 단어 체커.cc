#include<iostream>
#include<cstring>
using namespace std;

int arr[30];

int main(void){
    string str;
    int N;
    cin >> N;
    int ans = 1; // 초기값 1 (그룹 단어 아닐 시 0)
    int cnt = 0;
    
    for(int i=0; i<N; i++){
        cin >> str;
        // 앞에서 나온 단어인데 끊겼다 또 나오면 그룹 단어 아닌 거임.
        // 단어는 알파벳 소문자로만 되어있고,
        arr[str[0]-'a']++; // out of index 방지
        for(int j=1; j<str.size(); j++){
            arr[str[j]-'a']++;
            if(arr[str[j]-'a'] > 1 && str[j-1] != str[j]) {
                ans = 0;
                break;
            }
        }
        if(ans) cnt++;
        memset(arr, 0, sizeof(arr)); // 초기화 주의
        ans = 1; // 초기화 주의
    }
    cout << cnt;
}
