#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int age;
    string name;
}ST;

bool compare(ST a, ST b){
    if(a.age < b.age) return true;
    else return false;
}

int main(void){
    int N;
    cin >> N;
    ST pos;
    
    vector<ST> vec;
    for(int i=0;i<N;i++){
        cin >> pos.age >> pos.name;
        vec.push_back(pos);
    }
    stable_sort(vec.begin(), vec.end(), compare);
    for(int i=0;i<N;i++){
        cout << vec[i].age << " " << vec[i].name << "\n";
    }
    
}