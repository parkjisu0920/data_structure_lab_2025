#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void) {
	int n;
	int result[9];
	
	printf("1~9 정수를 입력하세요: ");

	scanf_s("%d", &n);

	for (int i = 1; i <=  n + (9 - n); i++) {
		result[i - 1] = n * i;
	}

	for (int i = 1; i <= n + (9 - n); i++) {
		printf("%d * %d = %d", n, i, result[i - 1]);
		printf("\n");
	}




	return 0;
}
