#include<stdio.h>
#include<stdlib.h>

int N, E;
int** matrix;  // int* x N개
int* visit;
int* size;
int cnt;

void makeList(int n1, int n2) {

	matrix[n1][size[n1]++] = n2;
	matrix[n2][size[n2]++] = n1;

	matrix[n1] = realloc(matrix[n1], (size[n1] + 1) * sizeof(int));
	matrix[n2] = realloc(matrix[n2], (size[n2] + 1) * sizeof(int));
}

void DFS(int v) {
	visit[v] = 1;
	for (int i = 0; i < size[v]; i++) {
		if (!visit[matrix[v][i]]) {
			cnt++;
			DFS(matrix[v][i]);
		}
	}
}

void init(void) {
	matrix = (int**)calloc(N, sizeof(int*));
	visit = (int*)malloc(N * sizeof(int));
	memset(visit, 0, N * sizeof(int));
	size = (int*)calloc(N, sizeof(int));
	//memset(size, 0, C * sizeof(int));

	if (!matrix || !visit || !size) {
		exit(0);
	}
	for (int i = 0; i < N; i++) {
		matrix[i] = (int*)calloc(1, sizeof(int));
		size[i] = 0;
	}
}

void destroy(void) {
	free(visit);
	free(size);
	for (int i = 0; i < N; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

int main(void) {
	scanf("%d", &N);
	scanf("%d", &E);

	init();
	int f, t;
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &f, &t);
		makeList(f - 1, t - 1); // 정점번호를 0 ~ N-1
	}
	DFS(0);
	printf("%d", cnt);
	destroy();
}