#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main(void){
    int n;
    cin >> n;
    
    string name;
    string visit;
    map<string, string> log;
    vector<string> employee;
    
    for (int i=0;i<n;i++){
        cin >> name;
        cin >> visit;
        log[name] = visit;
    }
    for(auto it=log.begin(); it!=log.end(); it++){
        if(it->second == "enter") employee.push_back(it->first);
    }
    
    vector<string>::reverse_iterator it = employee.rbegin();

    for (; it != employee.rend(); it++)
        cout << *it << "\n";  
  
}