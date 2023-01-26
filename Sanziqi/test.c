#include "game.h"

void menu() {
	printf("**************************\n");
	printf("*******   1.play     *****\n");
	printf("*******   0.exit     *****\n");
	printf("**************************\n");
}

void game() {
	char board[ROW][COL];
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1) {
		//�����
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '*') {
		printf("��Ӯ��������\n");
		DisplayBoard(board, ROW, COL);
	}
	else if (ret == '#') {
		printf("���ź���������\n");
		DisplayBoard(board, ROW, COL);
	}
	else {
		printf("ƽ�֡�\n");
		DisplayBoard(board, ROW, COL);
	}
}

int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input) {
		case 1:
			game();

			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
}