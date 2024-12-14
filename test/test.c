// test.c
#include <stdio.h>
#define MAX_COUNT 10

typedef char MANE_TYPE[14];
typedef struct {
	MANE_TYPE name;
	int a_score;
	int b_score;
	int c_score;
	int sum;
	float average;
} Student;
Student people[10];
int count = 0;

int Menu() {
	printf("[Menu]\n");
	printf("1. .dat ���Ͽ��� ������ �б�\n");
	printf("2. �߰� �л� ���� �Է�\n");
	printf("3. .dat ���� ����\n");
	printf("4. ���� Ȯ�� (��� ��� ��)\n");
	printf("5. ����\n");
	printf("--------------------------------\n");

	int num;
	printf("����(1~5) : ");
	scanf_s("%d", &num);

	switch (num) {

	case 1:

		return 1;
	case 2:

		return 1;
	case 3:
		AddFriend(people);
		return 1;
	case 4:
		Calculate(people);
		return 1;
	case 5:
		return 0;

	}
}
/*
void Data_read() {
	Student data_list[10];
	FILE* p_file = fopen("students.dat", "r");

	if (NULL != p_file) {
		fread(data_list, sizeof(NAME_TYPE), 10, p_file);


		for (int i = 0; i < 10; i++) {
			printf("data_list : %d\n", data_list[i]);
		}
	}
}
*/

int AddFriend(Student* p_friend) {
	if (count < MAX_COUNT) {
		p_friend = p_friend + count;

		printf("\n���ο� �л� ������ �Է��ϼ���\n");
		printf("�̸�: ");
		scanf_s("%s", p_friend->name, sizeof(MANE_TYPE));
		
		printf("���� ����: ");
		scanf_s("%d", &p_friend->a_score, sizeof(int));

		printf("���� ����: ");
		scanf_s("%d", &p_friend->b_score, sizeof(int));

		printf("���� ����: ");
		scanf_s("%d", &p_friend->c_score, sizeof(int));

		p_friend->sum = (p_friend->a_score) + (p_friend->b_score) + (p_friend->c_score);
		p_friend->average = (p_friend->sum) / 3.0;
		printf("\n�Է��� �Ϸ��߽��ϴ�.\n");
		count++;
	}
	else {
		printf("�ִ� �ο��� �ʰ��Ͽ� �Է��� �� �� �����ϴ�.\n");
		printf("�ִ� %d������� ���� �����մϴ�.\n\n", MAX_COUNT);
	}
}

int Calculate(Student* p_friend) {
	if (count > 0) {
		printf("\n�л� ���� Ȯ��\n");
		printf("==============================\n");
		for (int i = 0; i < count; i++) {
			p_friend = p_friend + i;
			printf("�̸� : %-7s | ���� ���� : %d | ���� ���� : %d | ���� ���� : %d | ���� : %d | ��� : %0.1f\n",
				p_friend->name,
				p_friend->a_score,
				p_friend->b_score,
				p_friend->c_score,
				p_friend->sum,
				p_friend->average);
		}
		printf("==============================\n");
	}
	else {
		printf("\n��ϵ� �л��� �����ϴ�!\n");
	}
}


void main(void) {
	int ch;
	while (1) {
		ch = Menu();
		if (ch != 1) break;
	}
}