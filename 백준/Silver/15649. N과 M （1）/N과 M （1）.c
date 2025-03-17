#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int R[10]; // M개를 뽑는
int used[10];  // N개 숫자에서
int N, M;
void printf_result(int L) {
	for (int i = 0; i < L; ++i) {
		printf("%d ", R[i]);
	}
	printf("\n");
}
void func(int L) {
	if (L >= M) {
		printf_result(L);
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (used[i]) continue;
		used[i] = 1;
		R[L] = i;
		func(L + 1);
		used[i] = 0;
	}
}
int main(void) {
	scanf("%d %d", &N, &M);
	func(0);
	return 0;
}