#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int T;

	scanf("%d", &T);

	int a = 0;

	for (int i = 1; i < T + 1; i++) {   

		if (i % 10 == 3 || i % 10 == 6 || i % 10 == 9) {  // 1���ڸ� �Ǵ�
			printf("- ");
		}
		else if (i % 10 == 3 || i % 10 == 6 || i % 10 == 9) { // 10���ڸ� �Ǵ�
			
			if (i % 3 == 0) {
				if (i % 10 == 0) {
					printf("- ");
				}
				else {
					printf("-- ");
				}
			}
		
		}
		else {
			printf("- ");
		}
		
	}

	return 0;
}
