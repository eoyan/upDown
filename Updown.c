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
	printf("1���� 100���� �ϳ��� ������ �����Ǿ����ϴ�.\n");
	return num;
}

void printHigher(int max, int min) {
	printf("���߾�� �� ������ �Է��� ���� %d ���� Ů�ϴ�.(�õ� Ƚ�� : %d ��)\n", min, count);
	if (count >= 5) {
		printf("5ȸ �ʰ�\n");
		draw = 0;
	}
	else printf("%d ~ %d ������ ������ �ٽ� �Է��ϼ���. > ", min + 1, max);
}

void printLower(int max, int min) {
	printf("���߾�� �� ������ �Է��� ���� %d ���� �۽��ϴ�. (�õ� Ƚ�� : %d ��)\n", max, count);
	if (count >= 5) {
		printf("5ȸ �ʰ�\n");
		draw = 0;
	}
	else printf("%d ~ %d ������ ������ �ٽ� �Է��ϼ���. > ", min, max);
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

	printf("�� ������ ���߾���� > ");
	while (draw) {

		scanf("%d", &user);

		if (system == user) {
			printf("�¾ҽ��ϴ�. �����մϴ�.");
			draw = 0;
		}
		else {
			printHead(system, user);
			count += 1;
		}

	}
}