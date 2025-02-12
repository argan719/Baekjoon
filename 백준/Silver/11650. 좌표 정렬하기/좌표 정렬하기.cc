#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

typedef struct{
    int x;
    int y;
}ST;

bool compare(ST a, ST b){
    if(a.x < b.x) return true;
    else if(a.x > b.x) return false;
    else {
        if(a.y < b.y) return true;
        else return false;
    }
}


int main(void){
    int N;
    cin >> N;
    
    ST pos;
    vector<ST> vec;
    for(int i=0;i<N;i++){
        cin >> pos.x >> pos.y;
        vec.push_back(pos);
    }
    sort(vec.begin(), vec.end(), compare);
    
    for(int i=0;i<vec.size();i++){
        cout << vec[i].x << " " << vec[i].y << "\n";
    }
    
}