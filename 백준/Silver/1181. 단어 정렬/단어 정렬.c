#include<stdio.h>
#define MAX_LEN 51
int N;
int* cnt;

typedef struct c {
	int len;
	char s[MAX_LEN];
}Word;
Word* arr;

int compLen(const void* a, const void* b) {
	if(((Word*)a)->len != ((Word*)b)->len) return (((Word*)a)->len - ((Word*)b)->len);
	return strcmp(((Word*)a)->s, ((Word*)b)->s);
}
/*
int compare(const void* a, const void* b) {
	char* s1 = *(const char**)a;
	char* s2 = *(const char**)b;
	if (strlen(s1) != strlen(s2)) return strlen(s1) - strlen(s2);
	return strcmp(s1, s2);
}*/

int main(void) {
	char n[MAX_LEN] = { 0 };
	int i, k;

	scanf("%d", &N);
	int cnt = 0;
	arr = (Word*)malloc(sizeof(Word) * N);
	cnt = (int*)malloc(sizeof(int) * N);

	// 넣을 때는 그냥 넣고 출력할 때 중복 확인을 해서 중복인 경우 건너뛰고 출력하면 됨.
	// 근데 일단 넣을 때부터 안 넣는 로직으로 해보려고 시도 중
	for (i = 0; i < N; i++) {
		scanf("%s", n);
		for (k = 0; k < i; k++) {
			if (!strcmp(arr[k].s, n)) {
				N--; i--;
				break;
			}
		}
		if (k == i) {
			strcpy(arr[i].s, n);
			arr[i].len = strlen(arr[i].s);
		}
	}

	qsort(arr, N, sizeof(Word), compLen);

	for (int i = 0; i < N; i++) {
		printf("%s\n", arr[i].s);
	}
}