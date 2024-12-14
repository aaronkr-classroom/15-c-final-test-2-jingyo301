#pragma once

void Data_read() {
	int data1,
		data2,
		data_list[5];
	FILE* p_file = fopen("students.dat", "r");

	if (NULL != p_file) {
		fread(&data1, sizeof(int), 1, p_file);
		fread(&data2, sizeof(int), 1, p_file);
		fread(data_list, sizeof(int) * 5, 1, p_file);
		// int data1 =0x00000412;
		printf("file data : %d (0x%04x)\n", data1, data1);
		// int data2 = 100;
		printf("file data : %d\n", data2);
		// int data_list = { 0, 1, 2, 3, 4 };
		for (int i = 0; i < 5; i++) {
			printf("data_list : %d\n", data_list[i]);
		}
	}
}

void Menu() {
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
	printf("%d", num);

	switch (num) {
	case 1:
		Data_read();
	case 2:
	case 3:
	case 4:
	case 5:
		return 0;
	}
}