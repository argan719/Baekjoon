#include<iostream>
#include<string>
using namespace std;

char matrix[20][20];
int R, C;
bool alphabet[26];
int max_cnt;
// 상 하 좌 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int compare(int a, int b) {
	if (a > b) return a; return b;
}

void dfs(int x, int y, int cnt) {
	max_cnt = compare(max_cnt, cnt);

	for (int i = 0; i < 4; i++) {
		int r = x + dx[i];
		int c = y + dy[i];

		if (r >= 0 && r < R && c >= 0 && c < C) {
			if (!alphabet[matrix[r][c]]) {
				alphabet[matrix[r][c]] = true;
				dfs(r, c, cnt + 1);
				alphabet[matrix[r][c]] = false;
			}
		}
	}
}

int main(void) {
	cin >> R >> C;
	string s;

	for (int i = 0; i < R; i++) {
        cin >> s;
		for (int k = 0; k < C; k++) {
			matrix[i][k] = s[k] - 'A';
		}
	}

	// A = 65
	// 1행1열.시작점
	alphabet[matrix[0][0]] = true;
	dfs(0, 0, 1);  // 카운트는 1부터 시작
	cout << max_cnt;
}