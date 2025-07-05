#include<iostream>
#include<stdio.h>
#include<algorithm> 
#include<vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int i;
	int s, e;

	vector<pair<int, int>> vec;

	for (i = 0; i < n; i++) {
		scanf("%d %d", &s,  &e);
		vec.push_back(make_pair(e, s));
	}
	sort(vec.begin(), vec.end());

	i = vec[0].first;
	int room = 1;
	for (int j = 1; j < n; j++) {
		if (vec[j].second >= i) {
			room++;
			i = vec[j].first;
		}
	}
	cout << room;
}