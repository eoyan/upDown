#define _CRT_SECURE_NO_WARNINGS
#define MAX 100;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int max = 100, min = 1, count = 1;
static int draw = 1;

int setNumber() {
	srand(time(NULL));
	int num = rand() % MAX + 1;
	printf("1에서 100까지 하나의 난수가 결정되었습니다.\n");
	return num;
}

void printHigher(int max, int min) {
	printf("맞추어야 할 정수가 입력한 정수 %d 보다 큽니다.(시도 횟수 : %d 번)\n", min, count);
	if (count >= 5) {
		printf("5회 초과\n");
		draw = 0;
	}
	else printf("%d ~ %d 사이의 정수를 다시 입력하세요. > ", min + 1, max);
}

void printLower(int max, int min) {
	printf("맞추어야 할 정수가 입력한 정수 %d 보다 작습니다. (시도 횟수 : %d 번)\n", max, count);
	if (count >= 5) {
		printf("5회 초과\n");
		draw = 0;
	}
	else printf("%d ~ %d 사이의 정수를 다시 입력하세요. > ", min, max);
}

void printHead(int system, int user) {
	if (system > user) {
		min = user;
		printHigher(max, min);
	}

	else {
		max = user;
		printLower(max, min);
	}
}

int main() {
	int system, user;
	system = setNumber();

	printf("이 정수를 맞추어보세요 > ");
	while (draw) {

		scanf("%d", &user);

		if (system == user) {
			printf("맞았습니다. 종료합니다.");
			draw = 0;
		}
		else {
			printHead(system, user);
			count += 1;
		}

	}
}