#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int x;
	int y;
	int h;
}Node;

Node* node;

int N, M, H;
int*** matrix = NULL;
int zcnt;
int rear;
int front;

void Enqueue(int h, int x, int y, int cnt) {
	node[rear].h = h;
	node[rear].x = x;
	node[rear].y = y;

	matrix[h][x][y] = cnt + 1;
	rear++;
}

Node Dequeue() {
	return node[front++];
}


void input() {
	int num;
	scanf("%d %d %d", &M, &N, &H);

	node = (Node*)malloc(sizeof(Node) * (N * M * H));  // 큐
	matrix = (int***)malloc(sizeof(int**) * H);  // 면

	for (int i = 0; i < H; i++) { // 행
		*(matrix + i) = (int**)malloc(sizeof(int*) * N);
		for (int k = 0; k < N; k++) {  // 열
			*(*(matrix + i) + k) = (int*)malloc(sizeof(int) * M);
		}
	}

	front = rear = 0;
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				scanf("%d", &num);
				matrix[h][n][m] = num;
				// 익은 토마토 전부 Enqueue
				if (num == 1) Enqueue(h, n, m, 0); 
				// 0인 토마토 개수 카운트
				if (!num) zcnt++;
			}
		}
	}
}

void BFS() {
	int dx[] = {-1, 1, 0, 0};
	int dy[] = { 0, 0, 1, -1 };
	int dh[] = { 1, -1 };  // 위, 아래

	int fh, fx, fy;  // future h, x, y
	Node tmp;
	int ch, cx, cy;
	int cnt;

	while (front != rear) {
		tmp = Dequeue();
		ch = tmp.h;
		cx = tmp.x;
		cy = tmp.y;
		cnt = matrix[ch][cx][cy];

		for (int i = 0; i < 2; i++) {
			fh = ch + dh[i];
			if (fh >= H || fh < 0) continue;
			if (!matrix[fh][cx][cy]) {
				Enqueue(fh, cx, cy, cnt);
				zcnt--;
				if (!zcnt) {
					printf("%d", cnt);
					return;
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			fx = cx + dx[i];
			fy = cy + dy[i];
			if (fx < 0 || fx >= N || fy < 0 || fy >= M) continue;
			if (!matrix[ch][fx][fy]) {
				Enqueue(ch, fx, fy, cnt);
				zcnt--;
				if (!zcnt) {
					printf("%d", cnt);
					return;
				}
			}
		}
	}
	printf("%d", -1);
}

void solve() {
	// 모든 토마토가 익어 있는 경우
	if (!zcnt) {
		printf("%d", 0);
		return;
	}
	BFS();
}

int main(void) {
	input();
	solve();
}