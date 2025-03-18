#include<stdio.h>
#define MAX 101
int matrix[MAX][MAX];
int visited[MAX][MAX];
typedef struct node {
	int x;
	int y;
	int cnt;
}Node;

int front;
int rear;
//int cnt;
int N, M;

Node q[MAX * MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void enqueue(int x, int y, int c) {
	visited[x][y] = 1;

	q[rear].x = x;
	q[rear].y = y;
	q[rear++].cnt = c+1;
}
Node dequeue() {
	return q[front++];
}

void bfs() {
	Node tmp;
	Node node;

	int x; 
	int y;

	while (front != rear) {
		tmp = dequeue();
		if (tmp.x == N && tmp.y == M) { printf("%d", tmp.cnt);  return; }

		for (int i = 0; i < 4; i++) {
			x = tmp.x + dx[i];
			y = tmp.y + dy[i];
			if (matrix[x][y] && !visited[x][y]) {
				enqueue(x, y, tmp.cnt);
			}
		}
	}

}

int main(void) {
	int n;
	Node tmp;
	char arr[MAX] = { 0 };
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%s", arr + 1);
		for (int k = 1; k <= M; k++) {
			matrix[i][k] = arr[k] - '0';
		}
	}  
	front = rear = 0;
	enqueue(1, 1, 0);
	bfs();
}