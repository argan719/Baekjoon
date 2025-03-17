#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int N, M;
int R[10];
void printf_result(int L) {
	for (int i = 0; i < L; ++i) {
		printf("%d ", R[i]);
	}
	printf("\n");
}

void func(int L, int prev) {
	if (L >= M) {
		printf_result(L);
		return;
	}
	for (int i = 1; i <= N; i++) {
		R[L] = i;
		func(L + 1, i);
	}
}
int main(void) {
	scanf("%d %d", &N, &M);
	func(0, 0);
	return 0;
}