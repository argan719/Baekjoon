#include<iostream>
#define MAX 1000001
#include<queue>
#include<map>
using namespace std;

int F, S, G, U, D;
int visited[MAX];

void bfs(){
    queue<int> q;
    map<int, int> m;
    q.push(S);
    visited[S] = 1;
    m[S] = 0;
    int up, down;
    
    while(!q.empty()){
        auto a = q.front();
        q.pop();
        
        if(a == G){
            cout << m[a];
            return;
        }
        
        up = a + U;
        down = a - D;
        if(1<=up && up <= F && !visited[up]) { 
            q.push(up); 
            visited[up] = 1; 
            m[up] = m[a] + 1;
        }
        if(1<= down && down <= F && !visited[down]) { 
            q.push(down); 
            visited[down] = 1; 
            m[down] = m[a] + 1;
        }
    }
    cout << "use the stairs";
}

int main(void){
    cin >> F >> S >> G >> U >> D;
    
    bfs();
}