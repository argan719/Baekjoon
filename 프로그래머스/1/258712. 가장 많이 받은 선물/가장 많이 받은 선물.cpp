#include <string>
#include <vector>
#include <algorithm>
#define MAX 51

using namespace std;

int info[MAX][MAX] = {0, };
int gift_level[MAX] = {0, };
// int igaveu[MAX] = {0, };
// int ireceive[MAX] = {0, };

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    for(int i=0;i<gifts.size();i++){
        int blank = gifts[i].find(' ');
        string front_name = gifts[i].substr(0, blank);
        string rear_name = gifts[i].substr(blank+1);
        
        int a = find(friends.begin(), friends.end(), front_name) - friends.begin();
        int b = find(friends.begin(), friends.end(), rear_name) - friends.begin();
        
        info[a][b]++;  // 첫 번째 비교를 하기 위함 (1:1로 비교)
        gift_level[a]++;
        gift_level[b]--;
    }
    vector<int> result(MAX);
    
    for(int i=0;i<friends.size();i++){
        for(int k=0;k<friends.size(); k++){
            if(i == k) continue;
            // 기록이 없거나 주고받은 수가 같은 경우 = 선물 지수 비교
            if(info[i][k] == info[k][i]) {
                if(gift_level[i] > gift_level[k]) result[i]++;
            }
            else if(info[i][k] > info[k][i]) result[i]++;
        }
    }
    
    answer = *max_element(result.begin(), result.end());
    
    return answer;
}