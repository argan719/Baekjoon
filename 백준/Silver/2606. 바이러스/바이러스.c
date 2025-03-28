#include<stdio.h>
#define MAX 102

int N, C;
int matrix[MAX][MAX];
int visited[MAX];

int cnt;
void AddEdge(int f, int t) {
	matrix[f][t] = 1;
	matrix[t][f] = 1;
}

void DFS(int v) {
	visited[v] = 1;
	for (int i = 1; i <= C; i++) {
		if (!visited[i] && matrix[v][i]) {
			cnt++;
			DFS(i);
		}
	}
}

int main(void) {
	scanf("%d", &C);
	scanf(" %d", &N);

	int f, t;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &f, &t);
		AddEdge(f, t);
	}
	DFS(1);
	printf("%d", cnt);
}