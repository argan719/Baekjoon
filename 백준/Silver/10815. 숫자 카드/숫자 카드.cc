#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> cards;
vector<int> numbers;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    int n;
    cin >> N;
    
    for(int i=0;i<N;i++){
         cin >> n;
         cards.push_back(n);
    }
    sort(cards.begin(), cards.end());  // 카드 정렬
    
    int mid, low, high;
    cin >> M;
    for(int i=0;i<M;i++){
        cin >> n;
        numbers.push_back(n);
    }
    for(int i=0;i<M;i++){
        low = 0; high = N-1;
        
        while(low <= high) {
            mid = (low + high) / 2;
            
            if(cards[mid] == numbers[i]) {cout << 1 << " "; break;}
            else if(cards[mid] < numbers[i]) low = mid + 1;
            else high = mid -1;
            
        }
        if(low > high) cout << 0 << " ";
    }
       
}
  