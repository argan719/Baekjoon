#include<iostream>
#define MAX 101
using namespace std;

int N;
int matrix[MAX][MAX];
int visited[MAX][MAX];

bool dfs(int h, int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N) return false;

	if (!visited[x][y] && matrix[x][y] > h) {
		visited[x][y] = 1;

		dfs(h, x - 1, y);
		dfs(h, x + 1, y);
		dfs(h, x, y - 1);
		dfs(h, x, y + 1);

		return true;
	}
	else return false;
}

void init() {
	for (int i = 0; i < N; i++) {
		for(int k = 0; k < N; k++) {
			visited[i][k] = 0;
		}
	}
}

int main(void) {
	cin >> N;
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cin >> matrix[i][k];
			if (max < matrix[i][k]) max = matrix[i][k];
		}
	}

	int height = 0;
	int cnt;
	int cnt_max = 0;
	while (height <= max) {
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < N; k++) {
				if (dfs(height, i, k)) cnt++;
			}
		}
		if (cnt > cnt_max) cnt_max = cnt;
		init();
		height++;
	}

	cout << cnt_max;
}