#include<stdio.h>
#define MAX 1001

typedef struct node {
    int x;
    int y;
}Node;

int zcnt;
int N, M;
int rear;
int front;

int matrix[MAX][MAX];
Node node[MAX * MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
void Enqueue(int x, int y) {
    node[rear].x = x;
    node[rear].y = y;
    
    rear++;
}

Node Dequeue() {
    return node[front++];
}

void bfs() {
    Node tmp;
    int r; int c;
    int days;

    while (front != rear) {
        tmp = Dequeue();  // 마지막에 dequeue된 토마토가 가장 늦게 익은 토마토겠지
        days = matrix[tmp.x][tmp.y] + 1;
        
        for (int i = 0; i < 4; i++) {
            r = tmp.x + dx[i];
            c = tmp.y + dy[i];
            if (r < 0 || r >= N || c < 0 || c >= M) continue;
            if (matrix[r][c] == 0) {
                Enqueue(r, c);
                matrix[r][c] = days;
                //printf("\n%d\n", days);
                zcnt--;
                if (zcnt == 0) { printf("%d", days-1); return; }
            }
        }
    }
    printf("%d", -1);
    return;
}

void print(){
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            printf("%d ", matrix[i][k]);
        }
        printf("\n");
    }
}

int main() {
    scanf("%d %d", &M, &N);
    int n;

    front = rear = 0;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            scanf("%d", &n);
            if (n == 0) zcnt++;
            else if(n == 1) Enqueue(i,k);  // 익은 토마토 전부 enqueue
            matrix[i][k] = n;
        }
    }
    // 저장될 때부터 모든 토마토가 익어있는 상태, 0 출력
    if (!zcnt) {
        printf("%d", 0);
    }
    else bfs();
    
    

}