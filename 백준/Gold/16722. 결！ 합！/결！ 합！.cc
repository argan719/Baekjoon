#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct hop{
    int a, b, c;
};

//hop arr[100];  // 현재 그림에서 가능한 모든 합 조합
vector<hop> arr;

struct image{
    string S; // 도형의 모양
    string C; // 도형의 색상
    string B; // 배경 색상
};

image img[10];
int N;
int score = 0;
bool flag_a, flag_b, flag_c = false;
//int cnt_flag = 0;
int cnt_hop;
int cnt_G;
int comp[3];

// 가능한 모든 합의 집합 저장
void check(){
    for(int i=1; i<=7; i++){
        for(int j=i+1; j<=8; j++){
            for(int k=j+1; k<=9; k++){
                
                if(img[i].S == img[j].S && img[j].S == img[k].S) flag_a = true;
                else if(img[i].S != img[j].S && img[i].S != img[k].S && img[j].S != img[k].S) flag_a = true;
                
                if(img[i].C == img[j].C && img[j].C == img[k].C) flag_b = true;
                else if(img[i].C != img[j].C && img[i].C != img[k].C && img[j].C != img[k].C) flag_b = true;
                
                if(img[i].B == img[j].B && img[j].B == img[k].B) flag_c = true;
                else if(img[i].B != img[j].B && img[i].B != img[k].B && img[j].B != img[k].B) flag_c = true;
                
                if(flag_a && flag_b && flag_c) {
                    comp[0] = i; comp[1] = j; comp[2] = k;
                    sort(comp, comp+3);
                    arr.push_back({comp[0], comp[1], comp[2]});
                }
                flag_a = false, flag_b = false, flag_c = false;
            }
        }
    }
    cnt_hop = arr.size();
}

void solve(char type, int ca, int cb, int cc){
    bool ans = true;
    if(type == 'H'){
        comp[0] = ca; comp[1] = cb; comp[2] = cc;
        sort(comp, comp+3);
        
        for(auto it = arr.begin(); it < arr.end(); it++){
            if(it->a == comp[0] && it->b == comp[1] && it->c == comp[2]) {
                score++;
                ans = false;
                it->a = 0; it->b = 0; it->c = 0;
                cnt_hop--;
            }
        }
        if(ans) score--;
    }
    else if(type == 'G'){
        if(cnt_hop == 0 && cnt_G == 0) {
            score += 3;
            cnt_G++;
        }
        else score--;
    }
}

void input(){
    char type;
    int a = 0, b = 0, c = 0;
    for(int i=1; i<=9; i++){
        cin >> img[i].S >> img[i].C >> img[i].B;
    }
    check();
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> type;
        if(type == 'H') cin >> a >> b >> c; // 입력 주의
        solve(type, a, b, c);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    cout << score << endl;
}
