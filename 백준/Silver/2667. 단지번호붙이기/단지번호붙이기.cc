#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define MAX 30
using namespace std;

int N;
int matrix[MAX][MAX];
int visited[MAX][MAX];

int cnt;
int dfs(int x, int y) {
	if (x < 0 || x > N || y < 0 || y > N) return 0;

	if (!visited[x][y] && matrix[x][y]) {
		cnt++;  // 단지 수 
		visited[x][y] = 1;

		dfs(x - 1, y);  // 좌
		dfs(x + 1, y);  // 우
		dfs(x, y - 1);  // 하
		dfs(x, y + 1);  // 상

	}
	return cnt;
}

int main(void) {
	cin >> N;
	string s;
	vector<int> house;

	// 2차원 배열에 0,1 숫자로 저장
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int k = 0; k < N; k++)
			matrix[i+1][k+1] = s[k] - '0';
	}

	int t;
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= N; k++) {
			cnt = 0;
			t = dfs(i, k);
			if (t != 0) house.push_back(t);
		}
	}

	cout << house.size() << endl;
	sort(house.begin(), house.end());
	for (int i = 0; i < house.size(); i++) {
		cout << house[i] << endl;
	}
}