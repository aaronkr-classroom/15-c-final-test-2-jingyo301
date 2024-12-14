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
	printf("1. .dat 파일에서 데이터 읽기\n");
	printf("2. 추가 학생 정보 입력\n");
	printf("3. .dat 파일 저장\n");
	printf("4. 성적 확인 (평균 계산 등)\n");
	printf("5. 종료\n");
	printf("--------------------------------\n");

	int num;
	printf("선택(1~5) : ");
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

		printf("\n새로운 학생 정보를 입력하세요\n");
		printf("이름: ");
		scanf_s("%s", p_friend->name, sizeof(MANE_TYPE));
		
		printf("국어 점수: ");
		scanf_s("%d", &p_friend->a_score, sizeof(int));

		printf("영어 점수: ");
		scanf_s("%d", &p_friend->b_score, sizeof(int));

		printf("수학 점수: ");
		scanf_s("%d", &p_friend->c_score, sizeof(int));

		p_friend->sum = (p_friend->a_score) + (p_friend->b_score) + (p_friend->c_score);
		p_friend->average = (p_friend->sum) / 3.0;
		printf("\n입력을 완료했습니다.\n");
		count++;
	}
	else {
		printf("최대 인원을 초과하여 입력을 할 수 없습니다.\n");
		printf("최대 %d명까지만 관리 가능합니다.\n\n", MAX_COUNT);
	}
}

int Calculate(Student* p_friend) {
	if (count > 0) {
		printf("\n학생 성적 확인\n");
		printf("==============================\n");
		for (int i = 0; i < count; i++) {
			p_friend = p_friend + i;
			printf("이름 : %-7s | 국어 점수 : %d | 영어 점수 : %d | 수학 점수 : %d | 총점 : %d | 평균 : %0.1f\n",
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
		printf("\n등록된 학생이 없습니다!\n");
	}
}


void main(void) {
	int ch;
	while (1) {
		ch = Menu();
		if (ch != 1) break;
	}
}