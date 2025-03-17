#define _CRT_SECURE_NO_WARNINGS
#define MAX 15
#include<stdio.h>
int N;
int left[MAX * 2];
int right[MAX * 2];
int col[MAX];
int cnt;

void func(int L) {
	if (L >= N) {
		cnt++;
		return;
	}
	for (int k = 0; k < N; k++) {
		if (!left[L - k + N - 1] && !right[L + k] && !col[k]) {
			left[L - k + N - 1] = 1;
			right[L + k] = 1;
			col[k] = 1;

			func(L + 1);

			left[L - k + N - 1] = 0;
			right[L + k] = 0;
			col[k] = 0;
		}
		
	}

}

int main(void) {
	scanf("%d", &N);
	func(0);
	printf("%d", cnt);
	return 0;
}