#include "game.h"

void menu() {
	printf("**************************\n");
	printf("*******   1.play     *****\n");
	printf("*******   0.exit     *****\n");
	printf("**************************\n");
}

void game() {
	char board[ROW][COL];
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1) {
		//玩家走
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//电脑走
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '*') {
		printf("你赢啦！！！\n");
		DisplayBoard(board, ROW, COL);
	}
	else if (ret == '#') {
		printf("很遗憾，你输了\n");
		DisplayBoard(board, ROW, COL);
	}
	else {
		printf("平局。\n");
		DisplayBoard(board, ROW, COL);
	}
}

int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input) {
		case 1:
			game();

			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
}